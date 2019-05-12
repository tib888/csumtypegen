#include <string>

class States
{
public:
    enum Tags
    {
        First,
        Second,
        Third,
        Fourth,
        Last
    };

private:
    Tags _tag;

    union {
        int _Second;
        int _Third;
        std::string _Fourth;
    };

    States(Tags tag) : _tag(tag)
    {
    }

    States(Tags tag, int value) : _tag(tag),
                                  _Second(value)
    {
    }

    States(Tags tag, std::string value) : _tag(tag),
                                          _Fourth(value)
    {
    }

public:
    ~States()
    {
        //call only the required destructor explicitly
        switch (_tag)
        {
        case Second:
            _Second.~int();
            break;
        case Tags::Third:
            _Third.~int();
            break;
        case Tags::Fourth:
            _Fourth.~string();
            break;
        }
    }

    Tags tag() { return _tag; };

    static States First()
    {
        return States(First);
    }

    static States Second(int value)
    {
        return States(Second, value);
    }

    static States Third(int value)
    {
        return States(Third, value);
    }

    static States Fourth(std::string value)
    {
        return States(Fourth, value);
    }

    static States Last()
    {
        return States(Tags::Last);
    }
};