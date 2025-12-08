#pragma once
#include "BaseInputStream.hpp"


class BoolInputStream :
    public BaseInputStream<bool>
{
protected:
    BoolInputStream();

    bool isCorrectType(string const& data) override;
    void changeType(bool& var, string const& data) override;

public:
    BoolInputStream(istream& in);
};

