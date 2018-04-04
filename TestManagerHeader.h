#ifndef TESTMANAGERHEADER_H
#define TESTMANAGERHEADER_H
#include <QtCore/QtCore>

namespace TestItemCommon{

//测试项
typedef struct _TestItem
{
    _TestItem() {
        idTestItem.clear();
        nameTestItem.clear();
        idDevice.clear();
        testType = 0;
        powerType = 0;
        targetTestItem.clear();
        setValue.clear();
        unitTestItem.clear();
        matrixEnter.clear();
        matrixOut.clear();
        methodTestItem.clear();
        adjusting = 0;
        remarkTestItem.clear();
        isActive = false;
    }

    void operator = (const _TestItem& item)
    {
        this->idTestItem = item.idTestItem;
        this->nameTestItem = item.nameTestItem;
        this->idDevice = item.idDevice;
        this->testType = item.testType;
        this->powerType = item.powerType;
        this->targetTestItem = item.targetTestItem;
        this->setValue = item.setValue;
        this->unitTestItem = item.unitTestItem;
        this->matrixEnter = item.matrixEnter;
        this->matrixOut = item.matrixOut;
        this->methodTestItem = item.methodTestItem;
        this->adjusting = item.adjusting;
        this->remarkTestItem = item.remarkTestItem;
        this->isActive = item.isActive;
    }
    void init(){
        idTestItem.clear();
        nameTestItem.clear();
        idDevice.clear();
        testType = 0;
        powerType = 0;
        targetTestItem.clear();
        setValue.clear();
        unitTestItem.clear();
        matrixEnter.clear();
        matrixOut.clear();
        methodTestItem.clear();
        adjusting = 0;
        remarkTestItem.clear();
        isActive = false;
    }

    QString idTestItem;             //ID
    QString nameTestItem;           //测试项名称
    QString idDevice;               //所属设备ID
    int testType;                   //测试类型 0: 调试 1: 成品
    int powerType;                  //电源类型
    QString targetTestItem;         //测试指标
    QString setValue;               //设置值
    QString unitTestItem;           //单位
    QString matrixEnter;            //矩阵输入口
    QString matrixOut;              //矩阵输出口
    QString methodTestItem;         //测试方法
    int    adjusting;               //是否校准
    QString remarkTestItem;         //备注
    bool    isActive;               //是否停用 0 - 不可用 1 - 可用
}TestItem;

//测试类型
enum TestType
{
    TestTypeDebugging=0,            //调试
    TestTypeFinished                //成品
};

//校准
enum AdjustingType
{
    AutoAdJust=0,                   //自动校准
    ManualAdJust,                   //手动校准
    NoAdJust,                       //不校准
    NONE
};
//根据测试类型ID获取名称
QString getTestTypeString(TestType type);
//根据
QString getAdjustingTypeString(AdjustingType type);

AdjustingType getAdjustingType(QString tyStr);


inline QString getTestTypeString(TestType type)
{
    if(TestTypeDebugging == type){
        return QStringLiteral("调试");
    }else {
        return QStringLiteral("产品");
    }
    return QString();
}

inline QString getAdjustingTypeString(AdjustingType type)
{
    if(AutoAdJust == type){
        return QStringLiteral("自动校准");
    }else if(ManualAdJust == type){
        return QStringLiteral("手动校准");
    }else {
        return QStringLiteral("不校准");
    }
}

inline AdjustingType getAdjustingType(QString tyStr)
{
    if(QStringLiteral("自动校准") == tyStr){
        return AutoAdJust;
    }else if(QStringLiteral("手动校准") == tyStr){
        return ManualAdJust;
    }else if(QStringLiteral("不校准") == tyStr){
        return NoAdJust;
    }
    return NONE;
}
}// namespace TestItemCommon

Q_DECLARE_METATYPE(TestItemCommon::TestItem)

Q_DECLARE_TYPEINFO(TestItemCommon::TestItem, Q_COMPLEX_TYPE);
#endif // TESTMANAGERHEADER_H
