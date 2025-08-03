#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}


int main() {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom으로 정의된 함수" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom�으로 정의된 함수" << std::endl;
}