#include <iostream>

class Integer
{
public:
	Integer();
	Integer(unsigned units, bool sign);
	Integer(int num);

	//void SetSign(bool sign);
	//bool GetSign()const;

	//void Units(unsigned units);
	//unsigned Units()const;

	unsigned GetUnits()const;

	//auto ToString()const -> std::string;
	//auto ToInt()const -> int;

	//bool IsEven()const;
	//bool IsOdd()const;
	//bool IsPrime()const;
	//bool IsNegative()const;
	//bool IsPositive()const;

	Integer Summ(const Integer& other) const;
	Integer Subtract(const Integer& other) const;
	Integer Multiply(const Integer& other) const;
	//Integer Divide(const Integer& other) const;
	//Integer Power(const Integer& other) const;

	Integer operator+(const Integer& other)const
	{
		return /*this->*/Summ(other);
	}

	Integer operator-(const Integer& other)
	{
		return Subtract(other);
	}


	Integer operator*(const Integer& other)
	{
		return Multiply(other);
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
	units_ = 0;
	sign_ = 0;
}

Integer::Integer(unsigned units, bool sign)
{
	units_ = units;
	sign_ = sign;
}

//Integer::Integer(unsigned units)
//{
//	units_ = units;
//	sign_ = 0;
//}

Integer::Integer(int num)
{
	if (num > 0)
	{
		sign_ = 1;
	}
	else
	{
		sign_ = 0;
	}
}


int main()
{
	Integer val1{ 10 };
	Integer val2{ -9 };
	Integer res;
	res = val1 + val2;
	std::cout << res.GetUnits() << "\n";
	res = val1 - val2;
	std::cout << res.GetUnits() << "\n";
	res = val1 * val2;
	std::cout << res.GetUnits() << "\n";
}

Integer Integer::Summ(const Integer& other) const
{
	unsigned res;
	if (other.sign_)
	{
		res = this->units_ - other.units_;
		return Integer(res, 0);
	}
	else if (this->sign_)
	{
		res = other.units_ - this->units_;
	}
	else if (other.sign_ && this->sign_)
	{

	}
	return Integer(this->units_ + other.units_);
}

Integer Integer::Subtract(const Integer& other) const
{
	return Integer(this->units_ - other.units_);
}

Integer Integer::Multiply(const Integer& other) const
{
	unsigned res = 0;

	for (size_t i = 0; i < other.GetUnits(); i++)
	{
		res += this->units_;
	}


	return Integer(res);
}

unsigned Integer::GetUnits() const
{
	return units_;
}
