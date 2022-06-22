#pragma once

//식별자 만들기
#include <type_traits>

struct null_t {};

//자신이 유일한 컴포넌트인지 판단. 유니크 컴포넌트가 나올때까지 재귀(부모클래스로 올라감)
template<class T>
struct is_unique_component
{
	typedef typename T::component_identifier_t identifier_t;
	typedef typename identifier_t::parent_component parent_t;

	enum
	{
		value = std::conditional<identifier_t::is_unique, std::true_type, is_unique_component<parent_t>>::type::value
	};
};
template<>
struct is_unique_component<null_t>
{
	enum { value = false };
};

//유니크 컴포넌트를 가져온다.
template<class T>
struct get_unique_component
{
	typedef typename T::component_identifier_t identifier_t;
	typedef typename identifier_t::parent_component parent_t;

	typedef typename std::conditional<identifier_t::is_unique, T, typename get_unique_component<parent_t>::type>::type type;
};
template <>
struct get_unique_component<null_t>
{
	typedef null_t type;
};

template <class T>
struct get_component
{
	typedef typename std::conditional<
		is_unique_component<T>::value,
		typename get_unique_component<T>::type,
		T>::type type;
};

//자신과 부모 클래스의 타입을 가져오고, 유일한 컴포넌트인지(더이상 상속하지 않는지) 체크
template<class T1,class T2,bool _is_unique>
struct _component_identifier 
{
	typedef T1 current_component;
	typedef T2 parent_component;

	enum { is_unique = _is_unique };
};

//상수클래스(?)
//매개변수로 타입의 이름을 가져옴
#define DEFINE_COMPONENT(component_name,parent_component_name,unique_component) \
	public: \
		typedef _component_identifier<component_name,parent_component_name,unique_component> component_identifier_t; \
		static size_t getComponentId(void) {return reinterpret_cast<size_t>(&identifier); } \
		virtual const char* getComponentName_(void) {return #component_name;} \
		static const char* getComponentName(void) {return #component_name;} \
	private: \
		static component_identifier_t identifier; \

//타입의 식별자를 설정 
#define DECLEARE_COMPONENT(component_name) \
	component_name::component_identifier_t component_name::identifier; \
