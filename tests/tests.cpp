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

TEST(IteratorTest, firstTest) {
    MockIterator mock;

    EXPECT_CALL(mock, first()).Times(1).WillOnce(::testing::Return(0));

    int result = mock.first();
    EXPECT_EQ(result, 0);
}

TEST(IteratorTest, nextTest) {
    MockIterator mock;

    EXPECT_CALL(mock, next()).Times(1);

    mock.next();
}

TEST(IteratorTest, isDoneTest) {
    MockIterator mock;

    EXPECT_CALL(mock, isDone()).Times(1).WillOnce(::testing::Return(0));

    bool result = mock.isDone();
    EXPECT_FALSE(result);
}

TEST(IteratorTest, currentItemTest) {
    MockIterator mock;

    EXPECT_CALL(mock, currentItem()).Times(1).WillOnce(::testing::Return(0));

    int result = mock.currentItem();
    EXPECT_EQ(result, 0);
}

TEST(AggregateTest, createIteratorTest) {
    MockAggregate mock;

    EXPECT_CALL(mock, createIterator()).Times(1);

    mock.createIterator();

}
