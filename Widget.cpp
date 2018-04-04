#include "Widget.h"
#include "ui_Widget.h"

#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _pTask = new(std::nothrow) TaskImport;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSelFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Files (*.xlsx *.xls)"));
    if (!fileName.isEmpty()) {
        if (_pTask) {
            _pTask->setTaskFilePath(fileName);

            TaskCommon::TaskInfo info;
            bool ret = _pTask->readTaskInfo(info);
            if (ret) {
                qDebug() << "任务名称:" << info.nameTask;
                qDebug() << "任务类型:" << info.typeTask;
                qDebug() << "应用型号:" << info.modelNum;
                qDebug() << "产品代码:" << info.productCode;
                qDebug() << "图纸路径:" << info.drawingPath;
            }

            QList< QPair<TestItemCommon::TestItem, quint32> > testItems;
            ret = _pTask->readTestInfo(testItems);
            if (ret) {
                for (int i = 0; i < testItems.size(); i++) {
                    TestItemCommon::TestItem item = testItems.at(i).first;

                    qDebug() << "测试项" << QString::number(i + 1);
                    // 测试项名称
                    qDebug() << "测试项名称:" << item.nameTestItem;
                    // 测试类型
                    qDebug() << "测试类型:" << item.testType;
                    // 电源类型
                    qDebug() << "电源类型:" << item.powerType;
                    // 测试指标
                    qDebug() << "测试指标:" << item.targetTestItem;
                    // 测试值
                    qDebug() << "测试值:" << item.setValue;
                    // 单位
                    qDebug() << "单位:" << item.unitTestItem;
                    // 矩阵输入口
                    qDebug() << "矩阵输入口:" << item.matrixEnter;
                    // 矩阵输出口
                    qDebug() << "矩阵输出口:" << item.matrixOut;
                    // 测试次数
                    qDebug() << "测试次数:" << testItems.at(i).second;
                    // 是否校准
                    qDebug() << "是否校准:" << item.adjusting;
                    // 测试方法
                    qDebug() << "测试方法:" << item.methodTestItem;
                    // 备注
                    qDebug() << "备注:" << item.remarkTestItem;
                }
            }
        }
    }
}
