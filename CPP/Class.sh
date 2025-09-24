echo "#include <iostream>

class $2
{
    private:

    public:
    $2();
    $2(const $2 &copy);
    $2  &operator=(const $2 &copy);
    ~$2();
};" >> $1/header/$2.hpp

echo "#include \"$2.hpp\"

$2::$2()
{
    std::cout << \"Constructor for $2 called\" << std::endl;
}

$2::$2(const $2 &copy)
{
    std::cout << \"Copy Constructor for $2 called\" << std::endl;
}

$2  &$2::operator=(const $2 &copy)
{
    std::cout << \"assignment operator for $2 called\" << std::endl;
}

$2::~$2()
{
    std::cout << \"Destructor for $2 called\" << std::endl;
}" >> $1/src/$2.cpp