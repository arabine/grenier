#ifndef GRAPH_H
#define GRAPH_H

#include <qapplication.h>
#include <qlayout.h>

class Graph : public QWidget
{
	Q_OBJECT

private:
	QPainter *paint;
	
public:
    Graph(QWidget *parent, const char *name);
	~Graph(){}
	void paintRandom(int tab[200]);
	void afficheGaussien(float tab[200]);

protected:
    void paintEvent(QPaintEvent *);
	
};

#endif