#include "ringnode.h"

RingNode::RingNode()
{
	next = nullptr;
}

RingNode::~RingNode()
{
}

int RingNode::getAge(void)
{
	return OldAge;
}

void RingNode::setAge(int key)
{
	OldAge = key;
}

std::string RingNode::getDescription(void)
{
	return Description;
}

void RingNode::setDescription(std::string key)
{
	Description = key;
}

std::string RingNode::getData(void)
{
	return SymbolicData;
}

void RingNode::setData(std::string key)
{
	SymbolicData = key;
}

void RingNode::setNext(RingNode * key)
{
	next = key;
}

RingNode * RingNode::getNext(void)
{
	return next;
}

void RingNode::inkrementAge(void)
{
	OldAge = OldAge++;
}
