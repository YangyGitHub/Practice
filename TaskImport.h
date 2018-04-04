#ifndef TASKIMPORT_H
#define TASKIMPORT_H

#include <QObject>
#include "TaskManangerHeader.h"
#include "TestManagerHeader.h"
#include "XlsxExcel.h"

#include <QList>
#include <QPair>

class TaskImport : public QObject
{
    Q_OBJECT
public:
    explicit TaskImport(QObject *parent = 0);
    ~TaskImport();

    /**
     * @brief setTaskFilePath
     * @param fileName
     */
    bool setTaskFilePath(const QString& fileName);

    /**
     * @brief readTaskInfo
     * @param info
     */
    bool readTaskInfo(TaskCommon::TaskInfo& info);

    /**
     * @brief readTestInfo
     * @param testItems
     * @return
     */
    bool readTestInfo(QList< QPair<TestItemCommon::TestItem, quint32> >& testItems);

private:
    XlsxExcel*      _pXlsxExcel = NULL;
    QString         _fileName;
    bool            _bOpen = false;
};

#endif // TASKIMPORT_H
