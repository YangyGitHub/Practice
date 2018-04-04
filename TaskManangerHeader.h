#ifndef TASKMANANGERHEADER_H
#define TASKMANANGERHEADER_H
#include <QtCore/QtCore>
#include <QDateTime>

namespace TaskCommon{

//任务信息
typedef struct _TaskInfo
{
    _TaskInfo() {
        idTask.clear();
        nameTask.clear();
        stateTas = 0;
        typeTask = 0;
        UserID.clear();
        drawingPath.clear();
        productCode.clear();
        modelNum.clear();
        isActive = false;
    }

    void operator = (const _TaskInfo& item)
    {
        this->idTask = item.idTask;
        this->nameTask = item.nameTask;
        this->stateTas = item.stateTas;
        this->typeTask = item.typeTask;
        this->startTime = item.startTime;
        this->endTime = item.endTime;
        this->testTime = item.testTime;
        this->UserID = item.UserID;
        this->drawingPath = item.drawingPath;
        this->productCode = item.productCode;
        this->modelNum = item.modelNum;
        this->isActive = item.isActive;
    }
    void init(){
        idTask.clear();
        nameTask.clear();
        stateTas = 0;
        typeTask = 0;
        UserID.clear();
        drawingPath.clear();
        productCode.clear();
        modelNum.clear();
        isActive = false;
    }

    QString idTask;                 //任务ID
    QString nameTask;               //任务名称
    int stateTas;                   //任务状态
    int typeTask;                   //任务类型   0 - 调试  1 - 成品
    QDateTime startTime;            //开始时间
    QDateTime endTime;              //结束时间
    QDateTime testTime;             //测试时间
    QString UserID;                 //执行人
    QString drawingPath;            //图纸路径
    QString productCode;            //产品代码
    QString modelNum;               //应用型号
    bool    isActive;               //是否停用 0 - 不可用 1 - 可用
}TaskInfo;

//任务信息
typedef struct _TaskItemInfo
{
    _TaskItemInfo() {
        idTask.clear();
        idItem.clear();
        nameDevice.clear();
        index = 0;
        TestCount = 0;
        testStatues = 0;
        result.clear();
        isActive = false;
    }

    void operator = (const _TaskItemInfo& item)
    {
        this->idTask = item.idTask;
        this->idItem = item.idItem;
        this->nameDevice = item.nameDevice;
        this->index = item.index;
        this->TestCount = item.TestCount;
        this->testStatues = item.testStatues;
        this->result = item.result;
        this->isActive = item.isActive;
    }
    void init(){
        idTask.clear();
        idItem.clear();
        nameDevice.clear();
        index = 0;
        TestCount = 0;
        testStatues = 0;
        result.clear();
        isActive = false;
    }

    QString idTask;                 //所属任务ID
    QString idItem;                 //测试项ID
    QString nameDevice;             //使用设备名称
    QString Target;                 //测试指标
    int index;                      //当前测试项在当前任务中的序号
    int TestCount;                  //测试次数
    int testStatues;                //当前状态
    QString result;                 //测试结果
    bool    isActive;               //是否停用 0 - 不可用 1 - 可用
}TaskItemInfo;

bool compareTaskItemForIndex(const TaskItemInfo& item1,const TaskItemInfo& item2);

inline bool compareTaskItemForIndex(const TaskItemInfo& item1,const TaskItemInfo& item2)
{
    return item1.index >= item2.index;
}

}// namespace TaskCommon

Q_DECLARE_METATYPE(TaskCommon::TaskInfo)

Q_DECLARE_TYPEINFO(TaskCommon::TaskInfo, Q_COMPLEX_TYPE);
#endif // TASKMANANGERHEADER_H
