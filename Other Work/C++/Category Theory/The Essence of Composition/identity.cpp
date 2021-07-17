/*
An identity function takes an object and returns the exact object. I wish to handle cases when the object is passed with and without reference
*/
template <class T> T GetIdentity(T obj)
{
    return obj;
}

template <class T> T GetIdentity(T& obj)
{
    return obj;
}