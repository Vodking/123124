#include <iostream>

class Integer
{
public:
	Integer();
	Integer(unsigned units, bool sign);
	Integer(int num);

	void SetSign(bool sign);
	bool GetSign()const;

	void Units(unsigned units);
	unsigned Units()const;

	auto ToString()const -> std::string;
	auto ToInt()const -> int;

	bool IsEven()const;
	bool IsOdd()const;
	bool IsPrime()const;
	bool IsNegative()const;
	bool IsPositive()const;

	Integer Summ(const Integer& other) const;
	Integer Subtract(const Integer& other) const;
	Integer Multiply(const Integer& other) const;
	Integer Divide(const Integer& other) const;
	Integer Power(const Integer& other) const;

	Integer operator+(const Integer& other)const
	{
		return /*this->*/Summ(other);
	}

	friend Integer operator-(const Integer& lso, const Integer& rso)
	{
		return lso.Subtract(rso);
	}

	Integer operator--(void)
	{
		if (sign_)
		{
			units_ += 1;
		}
		else
		{
			units_ -= 1;
		}
		return *this;
	}
	Integer operator--(int)
	{
		auto result = *this;
		if (sign_)
		{
			units_ += 1;
		}
		else
		{
			units_ -= 1;
		}
		return *this;
	}
private:
	unsigned units_;
	bool sign_;
};

Integer::Integer()
{
}


int main()
{
	Integer val1{ 15 };
	Integer val2{ 11 };
	Integer res;
	res = 7 - val1;
}


