#include <iostream>

class Integer
{
public:
	Integer();
	Integer(unsigned units);
	//Integer(int num);

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

Integer::Integer(unsigned units)
{
	units_ = units;
	sign_ = 0;
}


int main()
{
	Integer val1{ 10 };
	Integer val2{ 9 };
	Integer res;
	res = val1 + val2;
	std::cout << res.GetUnits() << "\n";
	res = val1 - val2;
	std::cout << res.GetUnits() << "\n";
}

Integer Integer::Summ(const Integer& other) const
{
	return Integer(this->units_ + other.units_);
}

Integer Integer::Subtract(const Integer& other) const
{
	return Integer(this->units_ - other.units_);
}

Integer Integer::Multiply(const Integer& other) const
{

	return Integer();
}

unsigned Integer::GetUnits() const
{
	return units_;
}
