#include "CppUnitTest.h"
#include "../astra_l1/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		List* lst;

		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
		}

		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete lst;
		}

		TEST_METHOD(the_list_empty)
		{
			Assert::IsTrue(lst->isEmpty());
		}
		TEST_METHOD(the_list_not_empty)
		{
			lst->push_back(1);
			Assert::IsFalse(lst->isEmpty());
		}
		TEST_METHOD(get_size_correct_size)
		{
			Assert::AreEqual(int(lst->get_size()),0);
		}
		TEST_METHOD(get_size_incorrect_size)
		{
			lst->push_back(1);
			Assert::AreNotEqual(int(lst->get_size()), 0);
		}
		TEST_METHOD(at_correct_index)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			Assert::AreEqual(lst->at(1), 2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try {
				lst->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(push_back_into_empty_list)
		{
			lst->push_back(1);
			Assert::AreEqual(lst->at(0), 1);
		}
		TEST_METHOD(push_back_into_not_empty_list)
		{
			lst->push_back(1);
			lst->push_back(2);
			Assert::AreEqual(lst->at(1), 2);
		}
		TEST_METHOD(push_back_does_size_correct)
		{
			lst->push_back(1);
			lst->push_back(1);
			lst->push_back(1);
			Assert::AreEqual(int(lst->get_size()), 3);
		}
		TEST_METHOD(push_front_into_empty_list)
		{
			lst->push_front(1);
			Assert::AreEqual(lst->at(0), 1);
		}
		TEST_METHOD(push_front_into_not_empty_list)
		{
			lst->push_back(2);
			lst->push_front(1);
			Assert::AreEqual(lst->at(0), 1);
		}
		TEST_METHOD(push_front_does_size_correct)
		{
			lst->push_front(1);
			lst->push_front(1);
			lst->push_front(1);
			Assert::AreEqual(int(lst->get_size()), 3);
		}
		TEST_METHOD(pop_back_empty_list)
		{
			try {
				lst->pop_back();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Removing elements in an empty list is not possible", e.what());
			}
		}
		TEST_METHOD(pop_back_head_element)
		{
			lst->push_back(1);
			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}
		TEST_METHOD(pop_back_not_empty_list)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->pop_back();
			try {
				lst->at(2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(pop_back_does_size_correct)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->pop_back();
			Assert::AreEqual(int(lst->get_size()), 2);
		}
		TEST_METHOD(pop_front_empty_list)
		{
			try {
				lst->pop_front();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Removing elements in an empty list is not possible", e.what());
			}
		}
		TEST_METHOD(pop_front_head_element)
		{
			lst->push_back(1);
			lst->pop_front();
			Assert::IsTrue(lst->isEmpty());
		}
		TEST_METHOD(pop_front_not_empty_list)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->pop_front();
			Assert::AreEqual(lst->at(0), 2);
		}
		TEST_METHOD(pop_fron_does_size_correct)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->pop_front();
			Assert::AreEqual(int(lst->get_size()), 2);
		}
		TEST_METHOD(insert_incorrect_index)
		{
			try {
				lst->insert(1,1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(insert_correct_index)
		{
			lst->push_back(1);
			lst->push_back(3);
			lst->push_back(4);
			lst->insert(2, 1);
			Assert::AreEqual(lst->at(1), 2);
		}
		TEST_METHOD(insert_into_empty_list)
		{
			lst->insert(1, 0);
			Assert::AreEqual(lst->at(0), 1);
		}
		TEST_METHOD(insert_does_size_correct)
		{
			lst->push_back(2);
			lst->push_back(3);
			lst->insert(1, 0);
			Assert::AreEqual(int(lst->get_size()), 3);
		}
		TEST_METHOD(remove_incorrect_index)
		{
			try {
				lst->remove(2);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(remove_correct_index)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->remove(0);
			Assert::AreEqual(lst->at(0), 2);
		}
		TEST_METHOD(remove_does_size_correct)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->remove(1);
			Assert::AreEqual(int(lst->get_size()), 2);
		}
		TEST_METHOD(remove_empty_test)
		{
			lst->push_back(1);
			lst->remove(0);
			Assert::IsTrue(lst->isEmpty());
		}
		TEST_METHOD(clear_empty_list)
		{
			try {
				lst->clear();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Removing elements in an empty list is not possible", e.what());
			}
		}
		TEST_METHOD(clear_not_empty_list)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->clear();
			Assert::IsTrue(lst->isEmpty());
		}
		TEST_METHOD(set_incorrect_index)
		{
			try {
				lst->set(2,1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(set_not_empty_list)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->set(1,5);
			Assert::AreEqual(lst->at(1), 5);
		}
		TEST_METHOD(swap_incorrect_index)
		{
			try {
				lst->swap(2, 1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(swap_test_index1)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->swap(0, 2);
			Assert::AreEqual(lst->at(0), 3);
		}
		TEST_METHOD(swap_test_index2)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->swap(0, 2);
			Assert::AreEqual(lst->at(2), 1);
		}
	};
}
