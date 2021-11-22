#include "gtest.h"
#include "../stack/ClSt.h"

TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int> n);
}

TEST(TStack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> n(-2));
}

TEST(TStack, can_copied_stack) {
	TStack<int> n(2);
	n.Push(1);
	n.Push(2);
	TStack<int> c(n);
	
	EXPECT_EQ(c,n);
}
TEST(TStack, copied_stack_has_its_own_memory) {
	TStack<int> n(2);
	n.Push(1);
	TStack<int> c(n);
	c.Push(3);

	EXPECT_NE(c, n);
}
TEST(TStack, cant_pop_empty_stack) {
	TStack<int> n(2);
	
	ASSERT_ANY_THROW(n.Pop());
}

TEST(TStack, cant_push_full_stack) {
	TStack<int> n(2);
	n.Push(1);
	n.Push(2);
	ASSERT_ANY_THROW(n.Push(5));
}
TEST(TStack, can_push_not_full_stack) {
	TStack<int> n(2);
	n.Push(1);
	
	ASSERT_NO_THROW(n.Push(5));
}
TEST(TStack, can_pop_not_empty_and_equal_stack) {
	TStack<int> n(2);
	n.Push(1);

	EXPECT_EQ(1, n.Pop());
}
TEST(TStack, can_clear_full_stack) {
	TStack<int> n(2);
	n.Push(1);
	n.Push(2);
	n.Clear();
	EXPECT_EQ(true, n.Empty());
}
/*
могу создать не могу создать
могу создать и скопировать 2 разных стека(скопир модиф пуш и сравнить)
не могу извлечь из пустого
не могу добавить в полный
могу добавить в неполный
могу извлечь из неполного и сравнить

*/