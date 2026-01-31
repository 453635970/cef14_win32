#include "guocheng.h"
#include "jcj_c_api.h"
#include "StdFunction.h"
#include <vector>

extern "C" FORMULA_API void MA(int dataLen, float *pfOUT, float *pfData,
                               float *period)
{
  MyMA(dataLen, pfOUT, pfData, period, nullptr);
}

extern "C" FORMULA_API void REF(int DataLen, float *pfOUT, float *pfIN, float *n)
{
  MyREF(DataLen, pfOUT, pfIN, n, nullptr);
}

extern "C" FORMULA_API void duanxianbao1(float *pfOUT, int data_len, float *pfInClose)
{
  duanxianbao1(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao2(float *pfOUT, int data_len, float *pfInClose)
{
  duanxianbao2(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao3(float *pfOUT, int data_len, float *pfInClose)
{
  duanxianbao3(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao4(float *pfOUT, int data_len, float *pfInClose)
{
  duanxianbao4(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao5(float *pfOUT, int data_len, float *pfInClose)
{
  duanxianbao5(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao_JH1(float *pfOUT, int data_len, float *pfInClose, float *pfInHigh, float *pfLow)
{
  duanxianbao_JH1(data_len, pfOUT, pfInClose, pfInHigh, pfLow, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao_JH1EM(float *pfOUT, int data_len, float *pfInClose, float *pfInHigh, float *pfLow)
{
  duanxianbao_JH1EM(data_len, pfOUT, pfInClose, pfInHigh, pfLow, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao_JH2(float *pfOUT, int data_len, float *pfInClose, float *pfInHigh, float *pfLow)
{
  duanxianbao_JH2(data_len, pfOUT, pfInClose, pfInHigh, pfLow, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao_BUY01(float *pfOUT, int data_len, float *pfInClose, float *pfInHigh, float *pfLow)
{
  duanxianbao_BUY01(data_len, pfOUT, pfInClose, pfInHigh, pfLow, nullptr, nullptr);
}
extern "C" FORMULA_API void duanxianbao_SELL01(float *pfOUT, int data_len, float *pfInClose, float *pfInHigh, float *pfLow)
{
  duanxianbao_SELL01(data_len, pfOUT, pfInClose, pfInHigh, pfLow, nullptr, nullptr);
}

// 好股天机 天机
extern "C" FORMULA_API void haogutianji_tianji(int data_len, float *pfOUT, float *pfInClose, float *pfInHigh, float *pfInLow, float *pfInOpen)
{
  haogutianji_tianji(data_len, pfOUT, pfInClose, pfInHigh, pfInLow, pfInOpen, nullptr);
}

// 好股天机 MABDL
extern "C" FORMULA_API void haogutianji_MABDL(int data_len, float *pfOUT, float *pfInClose, float *pfInHigh, float *pfInLow, float *pfInOpen)
{
  haogutianji_MABDL(data_len, pfOUT, pfInClose, pfInHigh, pfInLow, pfInOpen, nullptr);
}

// 好股天机 主力
extern "C" FORMULA_API void haogutianji_zhuli(int data_len, float *pfOUT, float *pfInClose, float *pfInHigh, float *pfInLow, float *pfInOpen)
{
  haogutianji_zhuli(data_len, pfOUT, pfInClose, pfInHigh, pfInLow, pfInOpen, nullptr);
}

// 好股天机 飞天
extern "C" FORMULA_API void haogutianji_feitian(int data_len, float *pfOUT, float *pfInClose, float *pfInHigh, float *pfInLow, float *pfInOpen)
{
  haogutianji_feitian(data_len, pfOUT, pfInClose, pfInHigh, pfInLow, pfInOpen, nullptr);
}

// 好股天机 神仙
extern "C" FORMULA_API void haogutianji_shenxian(int data_len, float *pfOUT, float *pfInClose, float *pfInHigh, float *pfInLow, float *pfInOpen)
{
  haogutianji_shenxian(data_len, pfOUT, pfInClose, pfInHigh, pfInLow, pfInOpen, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_MACD(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_MACD(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_DIF(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_DIF(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_mandongline(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_mandongline(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_MACD120(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_MACD120(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_MACD250(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_MACD250(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_XG(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_XG(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_dahangqing(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_dahangqing(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void HaiDaoHqt_DEA(int data_len, float *pfOUT, float *pfInClose)
{
  HaiDaoHqt_DEA(data_len, pfOUT, pfInClose, nullptr, nullptr, nullptr, nullptr);
}

// ====================
// StdFunction.h 基础函数导出
// ====================

// 移动平均类
extern "C" FORMULA_API void EMA(int dataLen, float *pfOUT, float *pfData,
                                float *period)
{
  MyEMA(dataLen, pfOUT, pfData, period, nullptr);
}

extern "C" FORMULA_API void SMA(int dataLen, float *pfOUT, float *pfData,
                                float *period, float *weight)
{
  MySMA(dataLen, pfOUT, pfData, period, weight);
}

extern "C" FORMULA_API void WMA(int dataLen, float *pfOUT, float *pfData,
                                float *period)
{
  MyWMA(dataLen, pfOUT, pfData, pfData, period);
}

// 统计函数
extern "C" FORMULA_API void HHV(int dataLen, float *pfOUT, float *pfData,
                                float *period)
{
  MyHHV(dataLen, pfOUT, pfData, period, nullptr);
}

extern "C" FORMULA_API void LLV(int dataLen, float *pfOUT, float *pfData,
                                float *period)
{
  MyLLV(dataLen, pfOUT, pfData, period, nullptr);
}

extern "C" FORMULA_API void COUNT(int dataLen, float *pfOUT, float *pfCond,
                                  float *period)
{
  MyCOUNT(dataLen, pfOUT, pfCond, period, nullptr);
}

extern "C" FORMULA_API void BARSLAST(int DataLen, float *pfOUT, float *pfIN)
{
  MyBARSLAST(DataLen, pfOUT, pfIN, nullptr, nullptr);
}

extern "C" FORMULA_API void STD(int DataLen, float *pfOUT, float *pfIN, float period)
{
  MySTD(DataLen, pfOUT, pfIN, &period, nullptr);
}

// 逻辑运算
extern "C" FORMULA_API void CROSS(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyCROSS(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void LONGCROSS(int DataLen, float *pfOUT, float *pfA, float *pfB, float period)
{
  MyLONGCROSS(DataLen, pfOUT, pfA, pfB, &period);
}

extern "C" FORMULA_API void AND(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyAND(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void OR(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyOR(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void NOT(int DataLen, float *pfOUT, float *pfIN)
{
  MyNOT(DataLen, pfOUT, pfIN, nullptr, nullptr);
}

// 比较运算
extern "C" FORMULA_API void GREAT(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyGreate(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void BELOW(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyBelow(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void EQUAL(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyEqual(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void NOTEQUAL(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyNotEqual(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void GEQUAL(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyGEqual(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void BEQUAL(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyBEqual(DataLen, pfOUT, pfA, pfB, nullptr);
}

// 数学运算
extern "C" FORMULA_API void ADD(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyAdd(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void SUB(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MySub(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void MUL(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyMul(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void DIV(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyDiv(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void ABS(int DataLen, float *pfOUT, float *pfIN)
{
  MyABS(DataLen, pfOUT, pfIN, nullptr, nullptr);
}

extern "C" FORMULA_API void MAX(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyMAX(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void MIN(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyMIN(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void ROUND(int DataLen, float *pfOUT, float *pfIN)
{
  MyRound(DataLen, pfOUT, pfIN);
}

// 条件函数
extern "C" FORMULA_API void IF(int DataLen, float *pfOUT, float *pfCond, float *pfTrue, float *pfFalse)
{
  MyIF(DataLen, pfOUT, pfCond, pfTrue, pfFalse);
}

// 其他函数
extern "C" FORMULA_API void BACKSET(int DataLen, float *pfOUT, float *pfIN, float period)
{
  MyBACKSET(DataLen, pfOUT, pfIN, &period, nullptr);
}

extern "C" FORMULA_API void ISLASTBAR(int DataLen, float *pfOUT)
{
  MyISLASTBAR(DataLen, pfOUT, nullptr, nullptr, nullptr);
}

extern "C" FORMULA_API void BARSLASTCOUNT(int DataLen, float *pfOUT, float *pfCond)
{
  MyBARSLASTCOUNT(DataLen, pfOUT, pfCond, nullptr, nullptr);
}

extern "C" FORMULA_API void FILTER(int DataLen, float *pfOUT, float *pfIN, float period)
{
  MyFILTER(DataLen, pfOUT, pfIN, &period, nullptr);
}

extern "C" FORMULA_API void SLOPE(int DataLen, float *pfOUT, float *pfIN, float period)
{
  MySlope(DataLen, pfOUT, pfIN, &period, nullptr);
}

// 三角函数
extern "C" FORMULA_API void SIN(int DataLen, float *pfOUT, float *pfIN)
{
    MySIN(DataLen, pfOUT, pfIN, nullptr, nullptr);
}

// 其他计算函数
extern "C" FORMULA_API void BETWEEN(int DataLen, float *pfOUT, float *pfIN, float *pfA, float *pfB)
{
    MyBETWEEN(DataLen, pfOUT, pfIN, pfA, pfB);
}

extern "C" FORMULA_API void TROUGHBARS(int dataLen, float *pfOUT, float *pfPrice,
                                       float *pfPercent, int m)
{
    Cal_TROUGHBARS(dataLen, pfOUT, pfPrice, pfPercent, m);
}

extern "C" FORMULA_API void PEAKBARS(int dataLen, float *pfOUT, float *pfPrice,
                                     float *pfPercent, int m)
{
    Cal_PEAKBARS(dataLen, pfOUT, pfPrice, pfPercent, m);
}

extern "C" FORMULA_API void AVEDEV(int dataLen, float *pfOUT, float *pfData,
                                   float period)
{
    MyAVEDEV(dataLen, pfOUT, pfData, &period, nullptr);
}

extern "C" FORMULA_API void TOTALBARSCOUNT(int DataLen, float *pfOUT, float *pfA, float *pfB)
{
  MyTOTALBARSCOUNT(DataLen, pfOUT, pfA, pfB, nullptr);
}

extern "C" FORMULA_API void BARSCOUNT(int DataLen, float *pfOUT, float *pfINa)
{
  return MyBARSCOUNT(DataLen, pfOUT, pfINa, nullptr, nullptr);
}

extern "C" FORMULA_API void COVAR(int DataLen, float *pfOUT, float *pfA, float *pfB, float period)
{
   MyCOVAR(DataLen, pfOUT, pfA, pfB, &period);
}

extern "C" FORMULA_API void ZIG(int DataLen, float *pfOUT, float *pfIN, float percent)
{
    MyZIG(DataLen, pfOUT, pfIN, &percent, nullptr);
}

extern "C" FORMULA_API void COST(int DataLen, float *pfOUT, float *pfHigh,
                                 float *pfLow, float percent, float capital)
{
    Cal_Cost(DataLen, pfOUT, pfHigh, pfLow, percent, capital);
}

// ====================
// StdFunction.cpp 特殊函数导出
// ====================

extern "C" FORMULA_API float avoid_mask_float()
{
    return ::avoid_mask_as_float();
}

extern "C" FORMULA_API void WINNER(int DataLen,
                                      float *pfOUT,
                                      const float *pfParam,
                                      const float *pfHigh,
                                      const float *pfLow,
                                      const float *pfVolume,
                                      const float *pfCircleCapital)
{
    ::MyWINNER(DataLen, pfOUT, pfParam, pfHigh, pfLow, pfVolume, pfCircleCapital);
}
