#include <math.h>
#include <fstream>
using namespace std;

class OutOfMem{};
class IndexOutOfRange{};
class WrongDim{};

class CMatrix{
	private:	
	struct rcmatrix;
	rcmatrix* data;	
	public:
	class Cref;
	
	CMatrix();
	CMatrix(const CMatrix& cm);
	CMatrix(fstream& fs);
	void write();
	double* read() const;
	double* operator[]()const;
	CMatrix& operator=();
	CMatrix& operator=();
	~CMatrix();
	friend ostream & operator << (ostream & s, const CMatrix & matrix);
	friend ostream & operator << (ostream & s, const CMatrix::Cref& s1);
	friend CMatrix operator* (const CMatrix&, const CMatrix&);
	Cref operator[](unsigned int i);	
		
			
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
		this->kolumna=0;
		this->n=0;

	}

	rcmatrix(fstream& fs){

	fs >> this->wiersz;


	this->data=new double*[this->wiersz];
	for(unsigned i=0;i<this->wiersz;i++)
		fs >> this->kolumna;
		this->data[i]=new double[this->kolumna];

	for(unsigned int i=0;i<this->rows;i++)
	  for(unsigned int j=0;j<this->cols;j++){
		fs >> this->data[i][j];
		this->n=1;
	}
}

void CMatrix::write(unsigned int i, double*s)
{
	block=block->detach();
	block->data[i]=s;

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

CMatrix::CMatrix(fstream& fs){
block = new rcmatrix(fs);
}

CMatrix::CMatrix(const CMatrix& cm){
cm.block->n++;
block = cm.block;
}

CMatrix::~CMatrix(){
  if(--block->n==0)
    delete block;
}

CMatrix::CMatrix(){
        block = new rcmatrix();
}










