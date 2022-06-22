#pragma once

//�ĺ��� �����
#include <type_traits>

struct null_t {};

//�ڽ��� ������ ������Ʈ���� �Ǵ�. ����ũ ������Ʈ�� ���ö����� ���(�θ�Ŭ������ �ö�)
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

//����ũ ������Ʈ�� �����´�.
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

//�ڽŰ� �θ� Ŭ������ Ÿ���� ��������, ������ ������Ʈ����(���̻� ������� �ʴ���) üũ
template<class T1,class T2,bool _is_unique>
struct _component_identifier 
{
	typedef T1 current_component;
	typedef T2 parent_component;

	enum { is_unique = _is_unique };
};

//���Ŭ����(?)
//�Ű������� Ÿ���� �̸��� ������
#define DEFINE_COMPONENT(component_name,parent_component_name,unique_component) \
	public: \
		typedef _component_identifier<component_name,parent_component_name,unique_component> component_identifier_t; \
		static size_t getComponentId(void) {return reinterpret_cast<size_t>(&identifier); } \
		virtual const char* getComponentName_(void) {return #component_name;} \
		static const char* getComponentName(void) {return #component_name;} \
	private: \
		static component_identifier_t identifier; \

//Ÿ���� �ĺ��ڸ� ���� 
#define DECLEARE_COMPONENT(component_name) \
	component_name::component_identifier_t component_name::identifier; \
