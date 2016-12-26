

#include <qtable.h>

class MyQTable : public QTable
{
	Q_OBJECT

public:

	MyQTable ( int numRows, int numCols, QWidget * parent = 0, const char * name = 0 );

public slots:
	void checkValue(int, int);

signals:
	void recalcTotal();
};