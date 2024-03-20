#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.2/lab12.2it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1

{
    bool compareLists(Node* list1, Node* list2) {
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data != list2->data) {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return (list1 == nullptr && list2 == nullptr);
    }
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Node* L = nullptr;
            append(L, 1);
            append(L, -2);
            append(L, 3);
            append(L, -4);
            append(L, 5);

            Node* L1_expected = nullptr;
            append(L1_expected, 1);
            append(L1_expected, 3);
            append(L1_expected, 5);

            Node* L2_expected = nullptr;
            append(L2_expected, -2);
            append(L2_expected, -4);

            Node* L1_actual = nullptr;
            Node* L2_actual = nullptr;
            splitList(L, L1_actual, L2_actual);

            Assert::IsTrue(compareLists(L1_actual, L1_expected));

            Assert::IsTrue(compareLists(L2_actual, L2_expected));
		}
	};
}
