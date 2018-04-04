#include "XlsxExcel.h"
#include <QAxObject>
#include <windows.h>

XlsxExcel::XlsxExcel()
     : QObject(), _pXlsx(NULL)
{
     // custom code
}

XlsxExcel::~XlsxExcel(void)
{
    if (_pXlsx) {
        delete _pXlsx;
        _pXlsx = NULL;
    }
}

bool XlsxExcel::openExcel(const QString &fileName)
{
    Q_UNUSED(fileName);

    // 创建QXlsx操作对象
    _pXlsx = new(std::nothrow) QXlsx::Document(fileName);
    if (!_pXlsx) {
        return false;
    }

#if 0
    // 新建一个excel文档所需 删除已存在的默认sheet
    QStringList sheetNames = _pXlsx->sheetNames();
    foreach (QString sheetName, sheetNames) {
        _pXlsx->deleteSheet(sheetName);
    }
#endif

    return true;
}

QStringList XlsxExcel::getAllSheets()
{
    if (_pXlsx) {
        QStringList sheetNames = _pXlsx->sheetNames();
        return sheetNames;
    }
    return QStringList();
}

bool XlsxExcel::closeExcel(const QString &fileName)
{
    if (_pXlsx) {
        // 文档另存为
        if (!fileName.isEmpty()) {
            QStringList sheetNames = _pXlsx->sheetNames();
            if (sheetNames.size() > 0) {
                _pXlsx->selectSheet(sheetNames.at(0));
                _pXlsx->saveAs(fileName);
                return true;
            }
        }
    }
    return false;
}

bool XlsxExcel::addSheet(const QString &sheetName)
{
    if (_pXlsx) {
        return _pXlsx->addSheet(sheetName);
    }
    return false;
}

bool XlsxExcel::setActiveSheet(const QString &sheetName)
{
    if (_pXlsx) {
        return _pXlsx->selectSheet(sheetName);
    }
    return false;
}

bool XlsxExcel::writeCellValue(uint32_t row, uint32_t column, const QVariant &wValue, const QColor &color)
{
    if (_pXlsx) {
        QXlsx::Format format1; // 设置该单元的样式
        /*
        format1.setFontColor(QColor(Qt::red));                      // 文字为红色
        format1.setFontSize(15);                                    // 设置字体大小
        */
        if (color != QColor(Qt::white))
            format1.setPatternBackgroundColor(color);               // 背景颜色
        format1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);// 横向居中

        return _pXlsx->write(row, column, wValue, format1);
    }
    return false;
}

bool XlsxExcel::readCellValue(uint32_t row, uint32_t column, QVariant &rValue)
{
    if (_pXlsx) {
        rValue = _pXlsx->read(row, column);
        if (!rValue.isNull())
            return true;
    }
    return false;
}

bool XlsxExcel::setCellColummnWidth(uint32_t row, uint32_t column, uint32_t Width)
{
    Q_UNUSED(row)
    if (_pXlsx) {
        return _pXlsx->setColumnWidth(column, column, Width);
    }
    return false;
}

bool XlsxExcel::setCellColor(uint32_t row, uint32_t column, const QColor &color)
{
    if (_pXlsx) {
        _pXlsx->cellAt(row, column)->format().setPatternBackgroundColor(color);
        return true;
    }
    return false;
}

XlsxExcel::ExcelVersion XlsxExcel::inquireExcelVersion()
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    QAxObject application;
    ExcelVersion version = ExcelVersionUnknown;

    double inquireVersionArray[] = {8, 9, 10, 11, 12, 14, 15};
    ExcelVersion versionArray[] = {
                                    ExcelVersion1997,
                                    ExcelVersion2000,
                                    ExcelVersion2002,
                                    ExcelVersion2003,
                                    ExcelVersion2007,
                                    ExcelVersion2010,
                                    ExcelVersion2013
                                   };

    if (!(application.setControl("Excel.Application"))) {
        return version;
    }

    double inquireVersion = application.dynamicCall("Version").toString().toDouble();

    for (int i = 0; i < sizeof(inquireVersionArray) / inquireVersionArray[0]; i++) {
        if (inquireVersionArray[i] == inquireVersion) {
            version = versionArray[i];
        }
    }

    return version;
}

bool XlsxExcel::startService(void)
{
     // custom code
     return true;
}

void XlsxExcel::stopService(void)
{
     // custom code
}
