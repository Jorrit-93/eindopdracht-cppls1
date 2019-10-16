#include "harbor.h"

Harbor::Harbor(HarborName name)
	: name(name)
{
	
}

Harbor::~Harbor()
{
	delete distances;
	delete cannons;
	delete stocks;
	delete ships;
}

//void Harbor::enterHarbor(HarborName harbor)
//{
//	*this = HarborBuilder::
//}
