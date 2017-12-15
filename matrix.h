#include <math.h>
#include <fstream>
using namespace std;


class CMatrix{
	private:	
	struct rcmatrix;
	rcmatrix* data;	
	public:
	class Cref;
	
	CMatrix();
	void write();
	~CMatrix();
	//friendy	
		
			
};


struct CMatrix::rcmatrix
{
	double** data;
	unsigned int wiersz;
	unsigned int kolumna;
	unsigned int n;

	rcmatrix(){
		this->data=NULL;
		this->wiersz=0;
		

	}
}

void CMatrix::write()
{
	
}

class CMatrix::Cref  //string
{
  friend class rcstring;
  rcstring& s;
  int i;
  Cref (rcstring& ss, unsigned int ii): s(ss), i(ii) {};
public:
  operator char() const
  {
    cout << "operator char() const"<<endl;
    return s.read(i);
  }
  rcstring::Cref& operator = (char c)
  {
    cout << "void operator = (char c)"<<endl;
    s.write(i,c);
    return *this;
  }
  rcstring::Cref& operator = (const Cref& ref)
  {
    return operator= ((char)ref);
  }

	

};














