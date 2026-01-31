#include "jcj_register.h"
#include "jdxj_up.h"
#include "jdxj_down.h"
#include "zdld.h"
#include "dkxh.h"
#include "qstd.h"
#include "zldn.h"
#include "guocheng.h"
#include "xiangti.h"
#include <stddef.h>
#include "test_dll.h"

void WrapDrawXJT(int data_len,
                 float *pfOUT,
                 float *pfINa,
                 float *,
                 float *,
                 float *,
                 float *)
{

  DrawXJT(data_len, pfOUT, pfINa);
}

void WrapDrawF1(int data_len,
                float *pfOUT,
                float *pfINa, // CLOSE
                float *,
                float *,
                float *,
                float *)
{
  DrawF1(data_len, pfOUT, pfINa);
}

void WrapDrawSJT(int data_len,
                 float *pfOUT,
                 float *pfINa,
                 float *,
                 float *,
                 float *,
                 float *)
{
  DrawSJT(data_len, pfOUT, pfINa);
}

// 加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = {
    {1, (pPluginFUNC)&WrapDrawXJT},
    {2, (pPluginFUNC)&WrapDrawF1},
    {3, (pPluginFUNC)&WrapDrawSJT},
    {4, (pPluginFUNC)&DDXJDownDrawSJT},
    {5, (pPluginFUNC)&DDXJDownDrawY},
    {6, (pPluginFUNC)&DDXJDownDrawXJT},
    {7, (pPluginFUNC)&CalcXiao5},
    {8, (pPluginFUNC)&DuoKongXinHaoLow},
    {9, (pPluginFUNC)&DuoKongXinHaoHigh},
    {10, (pPluginFUNC)&QuShiTongDaoGTY1},
    {11, (pPluginFUNC)&QuShiTongDaoGTY2},
    {12, (pPluginFUNC)&QuShiTongDaoGTY3},
    {13, (pPluginFUNC)&QuShiTongDaoGTY4},
    {14, (pPluginFUNC)&QuShiTongDaoGTY5},
    {15, (pPluginFUNC)&QuShiTongDaoGTY6},
    {16, (pPluginFUNC)&QuShiTongDaoGTY7},
    {17, (pPluginFUNC)&QuShiTongDaoTY1},
    {18, (pPluginFUNC)&QuShiTongDaoTY2},
    {19, (pPluginFUNC)&QuShiTongDaoTY3},
    {20, (pPluginFUNC)&QuShiTongDaoTY4},
    {21, (pPluginFUNC)&QuShiTongDaoTY5},
    {22, (pPluginFUNC)&QuShiTongDaoTY6},
    {23, (pPluginFUNC)&QuShiTongDaoTY7},
    {24, (pPluginFUNC)&JcIndexWinner},
    {25, (pPluginFUNC)&_GetA1},
    {26, (pPluginFUNC)&_GetA2},
    {27, (pPluginFUNC)&_GetA3},
    {28, (pPluginFUNC)&_GetA4},
    {29, (pPluginFUNC)&_GetA5},
    {30, (pPluginFUNC)&_GetA6},
	{31, (pPluginFUNC)&_LongTGetB},
	{32, (pPluginFUNC)&_LongTGetS},
	{33, (pPluginFUNC)&_DingdxjGet1},
	{34, (pPluginFUNC)&_DingdxjGet2},
	{35, (pPluginFUNC)&_DingdxjGet3},
	{36, (pPluginFUNC)&_DingdxjGet4},
	{37, (pPluginFUNC)&_DingdxjGet5},
	{38, (pPluginFUNC)&_DingdxjGet6},
	{39, (pPluginFUNC)&_DingdxjGet7},
	{40, (pPluginFUNC)&_DingdxjGet8},
	{41, (pPluginFUNC)&Finance9_1},
	{42, (pPluginFUNC)&Finance9_2},
	{43, (pPluginFUNC)&Finance9_3},
	{44, (pPluginFUNC)&min_signal1},
	{45, (pPluginFUNC)&min_signal2},
	{46, (pPluginFUNC)&duanxianbao1},
	{47, (pPluginFUNC)&duanxianbao2},
	{48, (pPluginFUNC)&duanxianbao3},
	{49, (pPluginFUNC)&duanxianbao4},
	{50, (pPluginFUNC)&duanxianbao5},
	{51, (pPluginFUNC)&duanxianbao_JH1},
	{52, (pPluginFUNC)&duanxianbao_JH1EM},
	{53, (pPluginFUNC)&duanxianbao_JH2},
	{54, (pPluginFUNC)&duanxianbao_BUY01},
	{55, (pPluginFUNC)&duanxianbao_SELL01},
	{56, (pPluginFUNC)&HaiDaoHqt_MACD},
	{57, (pPluginFUNC)&HaiDaoHqt_DIF},
	{58, (pPluginFUNC)&HaiDaoHqt_mandongline},
	{59, (pPluginFUNC)&HaiDaoHqt_MACD120},
	{60, (pPluginFUNC)&HaiDaoHqt_MACD250},
	{61, (pPluginFUNC)&HaiDaoHqt_XG},
	{62, (pPluginFUNC)&HaiDaoHqt_dahangqing},
	{63, (pPluginFUNC)&HaiDaoHqt_DEA},
	{64, (pPluginFUNC)&haogutianji_MABDL},
	{65, (pPluginFUNC)&haogutianji_tianji},
	{66, (pPluginFUNC)&haogutianji_zhuli},
	{67, (pPluginFUNC)&haogutianji_feitian},
	{68, (pPluginFUNC)&haogutianji_shenxian},
	{69, (pPluginFUNC)&jinqiandai_VAR19},
	{70, (pPluginFUNC)&jinqiandai_VAR1A},
	{71, (pPluginFUNC)&jinqiandai_HSCG},
	{72, (pPluginFUNC)&jinqiandai_QSGW},
	{73, (pPluginFUNC)&jinqiandai_GD},
	{74, (pPluginFUNC)&jinqiandai_RED},
	{75, (pPluginFUNC)&jinqiandai_blue},
	{76, (pPluginFUNC)&jinqiandai_QNX},
	{77, (pPluginFUNC)&jinqiandai_SMX},
	{78, (pPluginFUNC)&jinpaiheima_xian1},
	{79, (pPluginFUNC)&jinpaiheima_xian2},
	{80, (pPluginFUNC)&jinpaiheima_jpdw},
	{81, (pPluginFUNC)&qinglong_chushui},
	{82, (pPluginFUNC)&wsjinboduan_kongpan},
	{83, (pPluginFUNC)&wsjinboduan_xiaoniutj},
	{84, (pPluginFUNC)&wsjinboduan_guanzhutj},
	{85, (pPluginFUNC)&wsjinboduan_zljiancang},
	{86, (pPluginFUNC)&wsjinboduan_zlzaixian},
	{87, (pPluginFUNC)&WSLiangChao_DDD},
	{88, (pPluginFUNC)&WSLiangChao_KKK},
	{89, (pPluginFUNC)&WSLiangChao_CPL},
	{90, (pPluginFUNC)&WSLiangChao_SML},
	{91, (pPluginFUNC)&WSLiangChao_DKPD},
	{92, (pPluginFUNC)&WSLiangChao_DLC},
	{93, (pPluginFUNC)&WSLiangChao_KLC},
	{94, (pPluginFUNC)&WSLiangChao_LC1},
	{95, (pPluginFUNC)&WSLiangChao_LC2},
	{96, (pPluginFUNC)&WSLiangChao_LC3},
	{97, (pPluginFUNC)&WSLiangChao_WP},
	{98, (pPluginFUNC)&WSLiangChao_WXL},
	{99, (pPluginFUNC)&fangpopu},
	{100, (pPluginFUNC)&poweiqianzhao},
	{101, (pPluginFUNC)&jiatupoS},
	{102, (pPluginFUNC)&jiandi},
	{103, (pPluginFUNC)&xiangdiB},
	{104, (pPluginFUNC)&xiangdingS},
	{105, (pPluginFUNC)&suopopu},
	{106, (pPluginFUNC)&suopojian},
	{107, (pPluginFUNC)&fangpojian},
	{108, (pPluginFUNC)&yinfangtupu},
	{109, (pPluginFUNC)&yangfangtupu},
	{110, (pPluginFUNC)&yinfangtujian},
	{111, (pPluginFUNC)&yangfangtujian},
	{112, (pPluginFUNC)&yinsuotujian},
	{113, (pPluginFUNC)&yangsuotujian},
	{114, (pPluginFUNC)&shuangtou},
	{115, (pPluginFUNC)&ZSDX_S3},
	{116, (pPluginFUNC)&ZHLB_v1},
	{117, (pPluginFUNC)&ZHLB_v2},
	{118, (pPluginFUNC)&ZHLB_v3},
	{119, (pPluginFUNC)&ZHLB_v4},
	{120, (pPluginFUNC)&ZHLB_v5 },
	{121, (pPluginFUNC)&ZHLB_v6 },
	{122, (pPluginFUNC)&LYXH_Line1 },
	{123, (pPluginFUNC)&LYXH_Line2 },
	{124, (pPluginFUNC)&LYXH_Line3 },
	{125, (pPluginFUNC)&LYXH_Line4 },
	{126, (pPluginFUNC)&LYXH_Line5 },
	{ 127, (pPluginFUNC)&QLX_Va1 },
	{ 128, (pPluginFUNC)&QLX_Va2 },
	{ 129, (pPluginFUNC)&QLX_GTY10 },
	{ 130, (pPluginFUNC)&QLX_GTY13 },
	{ 131, (pPluginFUNC)&QLX_GTY14 },
	{ 132, (pPluginFUNC)&QLX_GTY15 },
	{ 133, (pPluginFUNC)&QLX_TY3 },

	// 测试函数
	{1000, (pPluginFUNC)&TestEMA},
	{1001, (pPluginFUNC)&TestRef},
	{1002, (pPluginFUNC)&TestMax},
	{1003, (pPluginFUNC)&TestMin},
	{1004, (pPluginFUNC)&TestLLV},
	{1005, (pPluginFUNC)&TestHHV},
	{1006, (pPluginFUNC)&TestCount},
	{1007, (pPluginFUNC)&TestIF},
	{1008, (pPluginFUNC)&TestMA},
	{1009, (pPluginFUNC)&TestZIG},
	{0, NULL},
};



// 导出给TCalc的注册函数
bool RegisterThrdFunc(PluginTCalcFuncInfo **pFun)
{
  if (*pFun == NULL)
  {
    (*pFun) = g_CalcFuncSets;

    return true;
  }
  return false;
}
