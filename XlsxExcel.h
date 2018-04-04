#if !defined(XLSXEXCEL_H)
#define XLSXEXCEL_H

#include <QObject>
#include <inttypes.h>
#include <xlsxdocument.h>

class XlsxExcel : public QObject
{
    Q_OBJECT

public:
    XlsxExcel();
    virtual ~XlsxExcel(void);

    // excel版本
    enum ExcelVersion
    {
        ExcelVersion1997,
        ExcelVersion2000,
        ExcelVersion2002,
        ExcelVersion2003,
        ExcelVersion2007,
        ExcelVersion2010,
        ExcelVersion2013,
        ExcelVersionUnknown
    };

    /**
     * @brief openExcel     打开excel文件
     * @param fileName
     * @return
     */
    bool openExcel(const QString &fileName);

    /**
     * @brief getAllSheets  获取所有的sheets
     * @return
     */
    QStringList getAllSheets();

    /**
     * @brief closeExcel    关闭保存excel文件
     * @param fileName
     * @return
     */
    bool closeExcel(const QString &fileName = tr(""));

    /**
     * @brief addSheet      添加sheet
     * @param sheetName
     * @return
     */
    bool addSheet(const QString &sheetName);

    /**
     * @brief setActiveSheet 设置当前操作sheet
     * @param sheetName
     * @return
     */
    bool setActiveSheet(const QString &sheetName);

    /**
     * @brief writeCellValue 往某单元格写入数据
     * @param row
     * @param column
     * @param wValue
     * @param color
     * @return
     */
    bool writeCellValue(uint32_t row, uint32_t column, const QVariant &wValue, const QColor &color = QColor(Qt::white));

    /**
     * @brief readCellValue 从某单元格读出数据
     * @param row
     * @param column
     * @param rValue
     * @return
     */
    bool readCellValue(uint32_t row, uint32_t column, QVariant &rValue);

    /**
     * @brief setCellColummnWidth 设置某单元格宽度
     * @param row
     * @param column
     * @param Width
     * @return
     */
    bool setCellColummnWidth(uint32_t row, uint32_t column, uint32_t Width);

    /**
     * @brief setCellColor  设置某单元格背景颜色
     * @param row
     * @param column
     * @param color
     * @return
     */
    bool setCellColor(uint32_t row, uint32_t column, const QColor &color);

    /**
     * @brief inquireExcelVersion   查询excel版本
     * @return
     */
    ExcelVersion inquireExcelVersion();

protected:
    virtual bool startService(void);
    virtual void stopService(void);

private:
    QXlsx::Document* _pXlsx;
};

#endif // XLSXEXCEL_H
