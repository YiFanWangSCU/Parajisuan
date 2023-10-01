// 并行计算1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <string>
#include <format>
void executeThread()
{
	for(int i = 0; i < 5; i++)
	std::cout << "Hello Concurrent World from thread "<< std::endl;
}
void executeThreadWithSimpleArgs(int vValue , std::string vStr)
{
	std::cout << std::format("Arguments passed to child thread: {} and {}/n", vValue, vStr);
}
class CWallet {
public :
	CWallet():m_money(0){}
	int getMoney() { return m_money; }
	int addMoney(int vMoney)
	{
		for (int i = 0; i < vMoney; i++)
		{
			m_money++;
		}
		return m_money;
	}
	void addMoneyWithMutex(int vMoney)
	{
		m_Mutex.lock();
		for (int i = 0; i < vMoney; i++)
		{
			m_money++;
		}
		m_Mutex.unlock();
	}
	void addMoneyWithLockGuard(int vMoney)
	{
		std::lock_guard<std::mutex> lockGuard(m_Mutex);
		for (int i = 0; i < vMoney; i++)
		{
			m_money++;
		}
	}
private:
	int m_money;
	std::mutex m_Mutex;
};
int main()
{
    //std::thread ThreadObject(executeThread);//创建线程对象
	// for(int i = 0; i < 5; i++)
	//std::cout << "Hello Concurrent World from main!" << std::endl;
	//ThreadObject.join();
	// std::cout<< "Exiting from Main Thread" << std::endl;
	
	
	
	//std::thread ThreadObject(executeThreadWithSimpleArgs,4,std::string("TEST"));//创建线程对象带字符
	// for(int i = 0; i < 5; i++)
	// std::cout << "Hello Concurrent World from main!" << std::endl;
	// ThreadObject.join();
	// std::cout<< "Exiting from Main Thread" << std::endl;
	//测试CWallet的两个函数
	
	
	
	CWallet walletObject;
	//std::thread ThreadObject(&CWallet::addMoney, &walletObject, 500);//addmoney
	//测试addMoney
	
	
	//std::thread ThreadObject(&CWallet::addMoneyWith, &walletObject, 500);//addMoneyWith
	/*for (int i = 0; i < 5; i++)
		std::cout << "Hello Concurrent World from main!" << std::endl;
	ThreadObject.join();
	std::cout << "Final wallet money: " << walletObject.getMoney() << std::endl;*/


	//测试addMoneyWithMutex
	
	
	//std::thread ThreadObject(&CWallet::addMoneyWithMutex, &walletObject, 500);//addMoneyWithMutex
	//for(int i = 0; i < 5; i++)
	//std::cout<< "Hello Concurrent World from main!" << std::endl;
	//ThreadObject.join();
	//std::cout << "Final wallet money: " << walletObject.getMoney() << std::endl;
	//std::cout<< "Exiting from Main Thread" << std::endl;

	//测试addMoneyWithLockGuard
	std::thread ThreadObject(&CWallet::addMoneyWithLockGuard, &walletObject, 500);//addMoneyWithLockGuard
	for (int i = 0; i < 5; i++)
		std::cout << "Hello Concurrent World from main!" << std::endl;
	ThreadObject.join();
	std::cout << "Final wallet money: " << walletObject.getMoney() << std::endl;
	return 0;
	//
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
