#include "CNetStreamDlg.h"
#include <QMessageBox>

CNetStreamDlg::CNetStreamDlg(QWidget *parent) //���캯��
	: QDialog(parent)
{
	ui.setupUi(this); // ��ʼ��UI����

	setFixedSize(this->width(), this->height()); // �̶��Ի����С

	ui.btnStartPlay->setText(tr("start play")); // ���ð�ť�ı�
	ui.label_name->setText(tr("please intput url")); // ���ñ�ǩ�ı�
}

CNetStreamDlg::~CNetStreamDlg()
{
}

QString CNetStreamDlg::getUrl() const
{
	return m_url;
}

void CNetStreamDlg::on_btnStartPlay_clicked() //�����ť����ʼ����
{
	m_url = ui.lineEdit_url->text();  // ��������ȡURL
	if (m_url.isEmpty()) //���Ϊ��
	{
		QMessageBox::information(this, tr("tips"), tr("url is empty"));
		return;
	}

	if (!isValidUrl(m_url)) { //���URL��ʽ
		QMessageBox::warning(this, tr("tips"), tr("invalid url format"));
		return;
	}

	accept(); // �رնԻ��򲢷���QDialog::Accepted
}

// ��Ӹ�ʽ��֤
bool CNetStreamDlg::isValidUrl(const QString& url)
{
	// ������URL��ʽ
	QUrl qurl(url);
	return qurl.isValid() && !qurl.scheme().isEmpty();
}