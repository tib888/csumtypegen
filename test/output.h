#include <string>
#include "tuples.h"

// comment1
// comment2
 class States // comment2_
{
public:
    enum Tags
    {
    	_First,
    	_Second /* (int) */,
    	_Third /* (int) */,
    	_Fourth /* (std::string) */, //comment2__
    	_Last,
    };

private:
    Tags _tag;

    union
    {
		int Second;
		int Third;
		std::string Fourth;
    };

    States(Tags tag) : 
        _tag(tag)
    {
    }

    States(Tags tag, int value) : 
        _tag(tag),
        _Second(value)
    {
    }

    //This overload alreade exist above.
    /*
    States(Tags tag, int value) : 
        _tag(tag),
        _Third(value)
    {
    }
    */

    States(Tags tag, std::string value) : 
        _tag(tag),
        _Fourth(value)
    {
    }

public:
    ~States()
    {
        //call only the required destructor explicitly
        switch (_tag)
        {
        case Second: _Second.~int(); break;
        case Third: _Third.~int(); break;
        case Fourth: _Fourth.~std::string(); break;
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
        return States(Last);
    }
    

};

/* comment3
   comment4 */
 class States2 {
public:
    enum Tags
    {
    	_First,  //comment5
    	_Second /* (int*) */,
    	_Third /* (tuple<int,int,int>) */,
    	_Fourth /* (const std::tuple<std::string, std::tuple<int*, const int* const *>>) */,
    	_Last,
    };

private:
    Tags _tag;

    union
    {
		int* Second;
		tuple<int,int,int> Third;
		const std::tuple<std::string, std::tuple<int*, const int* const *>> Fourth;
    };

    States2(Tags tag) : 
        _tag(tag)
    {
    }

    States2(Tags tag, int* value) : 
        _tag(tag),
        _Second(value)
    {
    }

    States2(Tags tag, tuple<int,int,int> value) : 
        _tag(tag),
        _Third(value)
    {
    }

    States2(Tags tag, const std::tuple<std::string, std::tuple<int*, const int* const *>> value) : 
        _tag(tag),
        _Fourth(value)
    {
    }

public:
    ~States2()
    {
        //call only the required destructor explicitly
        switch (_tag)
        {
        case Second: _Second.~int*(); break;
        case Third: _Third.~tuple<int,int,int>(); break;
        case Fourth: _Fourth.~const std::tuple<std::string, std::tuple<int*, const int* const *>>(); break;
        }
    }

    Tags tag() { return _tag; };
    
    static States2 First() 
    {
        return States2(First);
    }
    
    static States2 Second(int* value) 
    {
        return States2(Second, value);
    }
    
    static States2 Third(tuple<int,int,int> value) 
    {
        return States2(Third, value);
    }
    
    static States2 Fourth(const std::tuple<std::string, std::tuple<int*, const int* const *>> value) 
    {
        return States2(Fourth, value);
    }
    
    static States2 Last() 
    {
        return States2(Last);
    }
    

};

hello;