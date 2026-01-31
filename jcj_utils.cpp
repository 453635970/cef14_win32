#include "jcj_utils.h"
#include <assert.h>
#include <iterator>
#include "StdFunction.h"
#include <cfloat>

JCJArray::JCJArray(size_t data_len) : data_(data_len) {}
JCJArray::JCJArray(size_t data_len, float init) : data_(data_len, init) {}

JCJArray::JCJArray(size_t data_len, float *array) : data_(data_len)
{
  memcpy(data_.data(), array, sizeof(float) * data_len);
}

size_t JCJArray::length() const
{
  return data_.size();
}

const float *JCJArray::data() const
{
  return data_.data();
}

float *JCJArray::multable_data()
{
  return data_.data();
}

void JCJArray::MemCopyTo(float *dest)
{
  memcpy(dest, data_.data(), sizeof(float) * length());
}

std::size_t JCJArray::size() const
{
  return data_.size();
}

JCJArray operator+(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyAdd(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator+(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left + right;
}

JCJArray operator+(int left, const JCJArray &right)
{
  JCJArray left_array(right.length(), left);
  return left_array + right;
}

JCJArray operator-(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MySub(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator-(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left - right;
}

JCJArray operator-(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left - right;
}

JCJArray operator-(int left, const JCJArray &right)
{
  JCJArray left_array(right.length(), static_cast<float>(left));
  return left_array - right;
}

JCJArray operator*(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyMul(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator*(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left * right;
}

JCJArray operator/(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyDiv(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator/(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left / right;
}

JCJArray operator/(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left / right;
}

JCJArray operator>(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyGreate(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator>(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left > right;
}

JCJArray operator>(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left > right;
}

JCJArray operator<(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyBelow(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray operator<(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left < right;
}

JCJArray operator<(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left < right;
}

JCJArray operator<=(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyBEqual(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator<=(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left <= right;
}

JCJArray operator<=(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left <= right;
}

JCJArray operator>=(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyGEqual(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator>=(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left >= right;
}

JCJArray operator>=(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left >= right;
}

JCJArray operator&&(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyAND(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator&&(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left && right;
}

JCJArray operator&&(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left && right;
}

JCJArray operator||(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyOR(result.length(), result.multable_data(), left.data(), right.data(),
       nullptr);
  return result;
}

JCJArray operator||(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left || right;
}

JCJArray operator||(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left || right;
}

JCJArray operator!=(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyNotEqual(result.length(), result.multable_data(), left.data(), right.data(),
             nullptr);
  return result;
}

JCJArray operator!=(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left != right;
}

JCJArray operator!=(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left != right;
}

JCJArray operator==(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyEqual(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray operator==(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left == right;
}

JCJArray operator==(const JCJArray &left, float right_num)
{
  JCJArray right(left.length(), right_num);
  return left == right;
}

JCJArray operator!(const JCJArray &left)
{
  return JCJNot(left);
}

JCJArray JCJEMA(const JCJArray &input, int number)
{
  JCJArray wrapper_number(input.length(), static_cast<float>(number));
  JCJArray result(input.length());
  MyEMA(result.length(), result.multable_data(), input.data(),
        wrapper_number.data(), nullptr);
  return result;
}

JCJArray JCJCross(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());

  MyCROSS(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray JCJLongCross(const JCJArray &left, const JCJArray &right, int number)
{
  const int length = left.length();
  JCJArray wrapper_number(length, static_cast<float>(number));
  JCJArray result(length);

  MyLONGCROSS(length, result.multable_data(), left.data(), right.data(),
              wrapper_number.data());
  return result;
}

JCJArray JCJRef(const JCJArray &input, int ref)
{
  JCJArray result(input.length());
  JCJArray wrapper_ref(input.length(), static_cast<float>(ref));

  MyREF(result.length(), result.multable_data(), input.data(),
        wrapper_ref.data(), nullptr);

  return result;
}

JCJArray JCJRef(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyREF(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);

  return result;
}

JCJArray JCJBarsLast(const JCJArray &input)
{
  JCJArray result(input.length());
  MyBARSLAST(result.length(), result.multable_data(), input.data(), nullptr,
             nullptr);
  return result;
}

JCJArray JCJLLV(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyLLV(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray JCJLLV(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), static_cast<float>(right_num));
  return JCJLLV(left, right);
}

JCJArray JCJNot(const JCJArray &input)
{
  JCJArray result(input.length());
  MyNOT(result.length(), result.multable_data(), input.data(), nullptr,
        nullptr);
  return result;
}

JCJArray JCJCount(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyCOUNT(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray JCJCount(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), right_num);
  return JCJCount(left, right);
}

JCJArray JCJHHV(const JCJArray &left, const JCJArray &right)
{
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyHHV(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray JCJHHV(const JCJArray &left, int right_num)
{
  JCJArray right(left.length(), right_num);
  return JCJHHV(left, right);
}

JCJArray JCJSMA(const JCJArray &x, int n_num, int m_num)
{
  JCJArray n(x.length(), n_num);
  JCJArray m(x.length(), m_num);

  JCJArray result(x.length());
  MySMA(result.length(), result.multable_data(), x.data(), n.data(), m.data());
  return result;
}

JCJArray JCJAbs(const JCJArray &in)
{
  JCJArray result(in.length());
  MyABS(result.length(), result.multable_data(), in.data(), nullptr, nullptr);
  return result;
}

JCJArray JCJMax(const JCJArray &left, int right_num)
{
  JCJArray out(left.length());
  JCJArray right(left.length(), right_num);
  MyMAX(out.length(), out.multable_data(), left.data(), right.data(), nullptr);
  return out;
}

JCJArray JCJMax(const JCJArray &left, const JCJArray &right)
{
  JCJArray out(left.length());
  MyMAX(out.length(), out.multable_data(), left.data(), right.data(), nullptr);
  return out;
}

JCJArray JCJIf(const JCJArray &cond, const JCJArray &t, int f_num)
{
  JCJArray out(cond.length());
  JCJArray f(cond.length(), f_num);
  MyIF(out.length(), out.multable_data(), cond.data(), t.data(), f.data());
  return out;
}

JCJArray JCJIf(const JCJArray &cond, const JCJArray &t, const JCJArray &t1)
{
  JCJArray out(cond.length());
  // JCJArray f(cond.length());
  MyIF(out.length(), out.multable_data(), cond.data(), t.data(), t1.data());
  return out;
}

JCJArray JCJIf(const JCJArray &cond, int t, int t1)
{
  JCJArray t_array(cond.length(), t);
  JCJArray t1_array(cond.length(), t1);
  return JCJIf(cond, t_array, t1_array);
}

JCJArray JCJIf(const JCJArray &cond, int t, const JCJArray &t1)
{
  JCJArray t_array(cond.length(), t);
  return JCJIf(cond, t_array, t1);
}

JCJArray JCJIf(const JCJArray &cond, const JCJArray &t, float f_num)
{
  JCJArray out(cond.length());
  JCJArray f(cond.length(), f_num);
  MyIF(out.length(), out.multable_data(), cond.data(), t.data(), f.data());
  return out;
}

JCJArray JCJBackSet(const JCJArray &x, int n_num)
{
  JCJArray out(x.length());
  JCJArray n(x.length(), n_num);
  MyBACKSET(x.length(), out.multable_data(), x.data(), n.data(), nullptr);
  return out;
}

JCJArray JCJMA(const JCJArray &x, int n_num)
{
  JCJArray out(x.length());
  JCJArray n(x.length(), n_num);
  MyMA(x.length(), out.multable_data(), x.data(), n.data(), nullptr);
  return out;
}

JCJArray JCJWiner(const JCJArray &x, const JCJArray &volume, const JCJArray &high, const JCJArray &low, const JCJArray &cirle_capital)
{
  JCJArray out(x.length());
    MyWINNER(x.size(), out.multable_data(), x.data(), high.data(), low.data(), volume.data(), cirle_capital.data());
  return out;
}

JCJArray JCJSlope(const JCJArray &x, int n_num)
{
  JCJArray out(x.length());
  JCJArray n(x.length(), n_num);
  MySlope(x.length(), out.multable_data(), x.data(), n.data(), nullptr);
  return out;
}

JCJArray JCJMin(const JCJArray &left, const JCJArray &right)
{
  JCJArray out(left.length());
  MyMIN(out.length(), out.multable_data(), left.data(), right.data(), nullptr);
  return out;
}

JCJArray JCJStd(const JCJArray &left, int right_num)
{
  JCJArray out(left.length());
  JCJArray right(left.length(), right_num);
  MySTD(out.length(), out.multable_data(), left.data(), right.data(), nullptr);
  return out;
}

JCJArray JCJWMA(const JCJArray &input, int number)
{
  JCJArray wrapper_number(input.length(), static_cast<float>(number));
  JCJArray result(input.length());
  MyWMA(result.length(), result.multable_data(), input.data(),
        wrapper_number.data(), nullptr);
  return result;
}

JCJArray JCJFILTER(const JCJArray &input, int number)
{
  JCJArray wrapper_number(input.length(), static_cast<float>(number));
  JCJArray result(input.length());
  MyFILTER(result.length(), result.multable_data(), input.data(),
           wrapper_number.data(), nullptr);
  return result;
}

JCJArray JCJCovar(const JCJArray &input, const JCJArray &t, const JCJArray &t1)
{
  JCJArray out(input.length());
    MyCOVAR(out.length(), out.multable_data(), input.data(), t.data(), t1.data());
  return out;
}

JCJArray JCJtotalbarscount(const JCJArray &input, const JCJArray &t)
{
  JCJArray out(input.length());
  MyTOTALBARSCOUNT(out.length(), out.multable_data(), input.data(), t.data(), nullptr);
  return out;
}

JCJArray JCJSIN(const JCJArray &input)
{
  JCJArray out(input.length());
    MySIN(out.length(), out.multable_data(), input.data(), nullptr, nullptr);
  return out;
}

JCJArray JCJBETWEEN(const JCJArray &input, const JCJArray &t, const JCJArray &t1)
{
  JCJArray out(input.length());
    MyBETWEEN(out.length(), out.multable_data(), input.data(), t.data(), t1.data());
  return out;
}

JCJArray JCJBETWEEN(const JCJArray &input, float t, float t1)
{
  JCJArray t_array(input.length(), t);
  JCJArray t1_array(input.length(), t1);
  return JCJBETWEEN(input, t_array, t1_array);
}

JCJArray JCJBARSCOUNT(const JCJArray &input)
{
  JCJArray out(input.length());
    MyBARSCOUNT(out.length(), out.multable_data(), input.data(), nullptr, nullptr);
  return out;
}

JCJArray JCJZig(const JCJArray &input, const JCJArray &t)
{
  JCJArray out(input.length());
    MyZIG(out.length(), out.multable_data(), input.data(), t.data(), nullptr);
  return out;
}

JCJArray JCJCost(const JCJArray& input, const JCJArray& t, float fPercent, float fLTGB)
{
	JCJArray out(input.length());
    Cal_Cost(out.length(), out.multable_data(), input.data(), t.data(), fPercent, fLTGB);
	return out;
}

JCJArray JCJTROUGHBARS(const JCJArray& input, const JCJArray& t, int nINc)
{
	JCJArray out(input.length());
    Cal_TROUGHBARS(out.length(), out.multable_data(), input.data(), t.data(), nINc);
	return out;
}