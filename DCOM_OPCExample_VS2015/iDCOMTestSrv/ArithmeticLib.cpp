// ArithmeticLib.cpp : CArithmeticLib 的实现

#include "stdafx.h"
#include "ArithmeticLib.h"


// CArithmeticLib



STDMETHODIMP CArithmeticLib::add(int nNum1, int nNum2, int * pnResult)
{
	// TODO: 在此添加实现代码
	*pnResult = nNum1 + nNum2;

	return S_OK;
}


STDMETHODIMP CArithmeticLib::sub(int nNum1, int nNum2, int * pnResult)
{
	// TODO: 在此添加实现代码
	*pnResult = nNum1 - nNum2;
	return S_OK;
}
