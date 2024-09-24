using namespace std;

class Temperature
{
public:
    Temperature(double degrees = 0.0, char scale = 'C', char format = 'D');
    
    void Input();
    bool Set(double deg, char s);
    bool SetFormat(char f);
    bool Convert(char sc);
    void Increment(int deg, char sc);

    int Compare(const Temperature & d) const;
    char GetScale() const;
    double GetDegrees() const;
    void Show() const;

private:
    double degrees;
    char scale;
    char format;
};