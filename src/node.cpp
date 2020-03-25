#include "node.h"
#include <iostream>
using namespace std;

node::node()
{
    info=-1;
    st=NULL;
    dr=NULL;
}
node::node(int x)
{
    info=x;
    st=NULL;
    dr=NULL;
}
node::~node()
{}
