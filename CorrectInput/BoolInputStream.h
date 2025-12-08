#pragma once
#include "BaseInputStream.hpp"


class BoolInputStream :
    public BaseInputStream<bool>
{
protected:
    bool isCorrectType(string const& data) override;
    void chageType(bool& var, string const& data) override;

public:
    BoolInputStream(istream& in);
};

