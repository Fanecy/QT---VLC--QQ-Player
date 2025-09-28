#include "CNetStreamDlg.h"
#include <QMessageBox>

CNetStreamDlg::CNetStreamDlg(QWidget *parent) //构造函数
	: QDialog(parent)
{
	ui.setupUi(this); // 初始化UI界面

	setFixedSize(this->width(), this->height()); // 固定对话框大小

	ui.btnStartPlay->setText(tr("start play")); // 设置按钮文本
	ui.label_name->setText(tr("please intput url")); // 设置标签文本
}

CNetStreamDlg::~CNetStreamDlg()
{
}

QString CNetStreamDlg::getUrl() const
{
	return m_url;
}

void CNetStreamDlg::on_btnStartPlay_clicked() //点击按钮，开始播放
{
	m_url = ui.lineEdit_url->text();  // 从输入框获取URL
	if (m_url.isEmpty()) //如果为空
	{
		QMessageBox::information(this, tr("tips"), tr("url is empty"));
		return;
	}

	if (!isValidUrl(m_url)) { //检查URL格式
		QMessageBox::warning(this, tr("tips"), tr("invalid url format"));
		return;
	}

	accept(); // 关闭对话框并返回QDialog::Accepted
}

// 添加格式验证
bool CNetStreamDlg::isValidUrl(const QString& url)
{
	// 检查基本URL格式
	QUrl qurl(url);
	return qurl.isValid() && !qurl.scheme().isEmpty();
}