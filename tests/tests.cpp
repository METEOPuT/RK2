#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "IIterator.h"
#include "IAggregate.h"

class MockIterator : public IIterator {
public:
    MOCK_METHOD0(first, int());
    MOCK_METHOD0(next, void());
    MOCK_METHOD0(isDone, bool());
    MOCK_METHOD0(currentItem, int());
};

class MockAggregate : public IAggregate {
public:
    MOCK_METHOD0(createIterator, IIterator*());
};
