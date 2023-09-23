#include"Lists.cpp"
#include"catch2/catch_test_macros.hpp"
#include"catch2/catch_session.hpp"

List l;
TEST_CASE("ListsEmptyPop", "[F1]")
{
	CHECK_THROWS(l.PopBack());
	CHECK_THROWS(l.PopFront());
}

TEST_CASE("ListsPush", "[F2]")
{
	int v{ 1 };
	l.PushBack(v);
	REQUIRE(l.Size() == v);
	CHECK(l.PopBack() == v);
}

TEST_CASE("ListsPop", "[F3]")
{
	int v{ 1 };
	l.PushFront(v);
	REQUIRE(l.Size() == v);
	CHECK(l.PopFront() == v);
}

TEST_CASE("ListsComplex", "[F4]")
{
	int i{ 0 };
	for (; i < 10; ++i)
	{
		l.PushBack(i);
		l.PushFront(i);
	}
	CHECK(l.Size() == i * 2);

	for (; i > 0; --i)
	{
		CHECK(l.PopBack() == i - 1);
		CHECK(l.PopFront() == i - 1);
	}
	CHECK(l.Size() == 0);
	CHECK_THROWS(l.PopBack());
	CHECK_THROWS(l.PopFront());
}


int main()
{
	Catch::Session().run();
	std::system("pause");
	return 0;
}