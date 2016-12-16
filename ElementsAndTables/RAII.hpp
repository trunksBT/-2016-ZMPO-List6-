#include <cassert>
#include <iostream>
#include <utility>

template <typename T>
class RAII
{
public:
	RAII(T* t) : t_ {t}
	{
	}
 
	RAII(const RAII&) = delete;
	RAII& operator=(const RAII&) = delete;
	RAII(RAII&& ptr)
	{
		std::swap(t_, ptr.t_);
	}
 
	~RAII()
	{
		delete[] t_;
	}

    RAII& operator=(RAII&& ptr)
	{
		std::swap(t_, ptr.t_);
		return *this;
	}
 
	explicit operator bool() const noexcept
	{
		return t_;
	}
 
	T* operator->() const noexcept
	{
		return t_;
	}
 
	T& operator *() const
	{
		assert(t_ && "nullptr");
		return *t_;
	}

private:
	T* t_ = nullptr;
};

template <class T>
auto make_ptr(std::size_t size)
{
    return RAII<T> {new T[size]};
}
  
// template <class T>
// class Table
// {
// public:
// 	Table()
// 		: memory_ {make_ptr<T>(10)}
// 	{
// 		throw 5;
// 		// memory_ is correctly freed
// 	}
 
// 	Table(std::size_t i)
// 		: memory_ {make_ptr<T>(i)}
// 	{
// 	}
 
// 	~Table()
// 	{
// 		std::cout << "All ok, Table dying" << std::endl;
// 	}
 
// private:
// 	RAII<T> memory_;
// };
 
// int main()
// {
// 	auto ptr = make_ptr<int>(5);
// 	std::cout << *ptr << ", !empty? " << static_cast<bool>(ptr) << '\n';
 
// 	auto x = std::move(ptr);
// 	std::cout << "!empty? " << static_cast<bool>(ptr) << '\n';
// 	std::cout << *x << ", !empty? " << static_cast<bool>(x) << '\n';
	
// 	try
// 	{
// 		Table<int> t {};
// 	}
// 	catch (...)
// 	{
// 		std::cout << "oops, fuckup" << std::endl;
// 	}
 
// 	try
// 	{
// 		Table<int> t {15};
// 	}
// 	catch (...)
// 	{
// 		std::cout << "oops, fuckup #2" << std::endl;
// 	}
// }