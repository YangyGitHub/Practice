#include "TaskImport.h"

TaskImport::TaskImport(QObject *parent) :
    QObject(parent)
{

}

TaskImport::~TaskImport()
{
    if (_bOpen) {
        delete _pXlsxExcel;
        _pXlsxExcel = NULL;
        _bOpen = false;
    }
}

bool TaskImport::setTaskFilePath(const QString &fileName)
{
    // 已经打开
    if (_bOpen) {
        delete _pXlsxExcel;
        _pXlsxExcel = NULL;
        _bOpen = false;
    }
    _pXlsxExcel = new(std::nothrow) XlsxExcel;
    if (_pXlsxExcel) {
        _bOpen = _pXlsxExcel->openExcel(fileName);
    }
    return _bOpen;
}

bool TaskImport::readTaskInfo(TaskCommon::TaskInfo &info)
{
    if (_pXlsxExcel && _bOpen) {
        QStringList sheets = _pXlsxExcel->getAllSheets();
        if (sheets.size() > 0) {
            _pXlsxExcel->setActiveSheet(sheets.at(0));

            //--------------------读取excel中内容--------------------//
            uint32_t row = 1;
            uint32_t column = 2;
            QVariant rValue;
            // 任务名称
            bool ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (ret) info.nameTask = rValue.toString();

            // 任务类型
            column += 2;
            ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (ret) info.typeTask = rValue.toString() == tr("成品") ? 1 : 0;

            // 应用型号
            column += 2;
            ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (ret) info.modelNum = rValue.toString();

            // 产品代码
            column += 2;
            ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (ret) info.productCode = rValue.toString();

            // 图纸路径
            column += 2;
            ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (ret) info.drawingPath = rValue.toString();

            return true;
        }
        return false;
    }
    return false;
}

bool TaskImport::readTestInfo(QList<QPair<TestItemCommon::TestItem, quint32> > &testItems)
{
    if (_pXlsxExcel && _bOpen) {
        QStringList sheets = _pXlsxExcel->getAllSheets();
        if (sheets.size() > 0) {
            _pXlsxExcel->setActiveSheet(sheets.at(0));

            //--------------------读取excel中内容--------------------//
            uint32_t row = 1;
            uint32_t column = 12;
            QVariant rValue;
            // 测试项数量
            bool ret = _pXlsxExcel->readCellValue(row, column, rValue);
            if (!ret) return false;
            quint32 num = rValue.toUInt();

            // 遍历测试项
            row = 4;    // 起始行位置
            for (quint32 i = 0; i < num; i++) {
                TestItemCommon::TestItem item;
                // 测试次数
                quint32 testNUM = 0;

                // 测试项名称
                column = 1;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.nameTestItem = rValue.toString();

                // 测试类型
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.testType = rValue.toString() == tr("成品") ? 1 : 0;

                // 电源类型
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.powerType = rValue.toString().toInt();

                // 测试指标
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.targetTestItem = rValue.toString();

                // 测试值
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.setValue = rValue.toString();

                // 单位
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.unitTestItem = rValue.toString();

                // 矩阵输入口
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.matrixEnter = rValue.toString();

                // 矩阵输出口
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.matrixOut = rValue.toString();

                // 测试次数
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) testNUM = rValue.toUInt();

                // 是否校准
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.adjusting = rValue.toString() == tr("是") ? 1 : 0;

                // 测试方法
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.methodTestItem = rValue.toString();

                // 备注
                column ++;
                ret = _pXlsxExcel->readCellValue(row + i, column, rValue);
                if (ret) item.remarkTestItem = rValue.toString();

                testItems.append(qMakePair(item, testNUM));
            }

            return true;
        }
        return false;
    }
    return false;
}
