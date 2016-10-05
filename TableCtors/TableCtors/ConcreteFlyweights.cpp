#include "stdafx.h"
#include "ConcreteFlyweights.h"

namespace trigger
{
CTable* FlyweightCTable::onCreateDef()
{
    return new CTable();
}
}
