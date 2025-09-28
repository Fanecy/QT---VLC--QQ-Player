#include "CommonUtils.h"
#include <QSettings>


CommonUtils::CommonUtils()
{
}

CommonUtils::~CommonUtils()
{
}

void CommonUtils::writeIni(QString inipath, QString keystr, QString value)
{
	
	QSettings *configIniWrite = new QSettings(inipath, QSettings::IniFormat);
	configIniWrite->setValue(keystr, value);

	// 检查是否写入成功
	bool success = (configIniWrite->status() == QSettings::NoError);

	//写入完成后删除指针
	delete configIniWrite;
}

QString CommonUtils::readIni(QString inipath, QString keystr)
{
	QString defaultValue = ""; //增加默认读取
	QSettings *configIniRead = new QSettings(inipath, QSettings::IniFormat);
	QString ipResult = configIniRead->value(keystr,defaultValue).toString();

	//读入入完成后删除指针
	delete configIniRead;

	return ipResult;
}