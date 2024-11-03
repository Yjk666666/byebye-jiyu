#include "other.h"
#include<qfile.h>
#include <QFileInfo>
bool isexe(QString s)
{
	QFile c(s);
	if (!c.exists())
		return false;
	return true;
}

QString toexe(QString s)
{
	QFileInfo inf(s);
	return inf.fileName();
}
