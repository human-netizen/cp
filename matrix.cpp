class Matrix
{

public:
    ll row, col;
    vector<vector<ll>> table;

    Matrix() {}
    Matrix(ll row, ll col , ll val)
    {
        this->row = row;
        this->col = col;
        table.resize(row, vector<ll>(col , val));
    }
    Matrix iden(){
        Matrix res(row , col , 0);
        for(ll i = 0 ; i < row ; i++){
            for(ll j = 0 ; j < col ; j++){
                if(i == j)res.table[i][j] = 1;
            }
        }
        return res;
    }
    friend istream &operator>>(istream &cin, Matrix &mat)
    {
        cin >> mat.row >> mat.col;
        for (ll i = 0; i < mat.row; i++)
        {
            vector<ll> rowTable;
            ll val;
            for (ll j = 0; j < mat.col; j++)
            {
                cin >> val;
                rowTable.push_back(val);
            }
            mat.table.push_back(rowTable);
        }
        return cin;
    }
    friend ostream &operator<<(ostream &cout, Matrix &mat)
    {
        for (ll i = 0; i < mat.table.size(); i++)
        {
            for (ll j = 0; j < mat.table[i].size(); j++)
            {
                cout << mat.table[i][j] << " ";
            }
            cout << endl;
        }
        return cout;
    }
    Matrix operator*(Matrix &mat2)
    {
        ll _row = mat2.row;
        ll _col = mat2.col;
        Matrix res(row, _col , 0);
        if (col != mat2.row)
            return res;
        //first colum 2nd row sem
        for (ll i = 0; i < row; i++)
        {
            for (ll j = 0; j < _col; j++)
            {
                ll val = 0;
                for (ll k = 0; k < col; k++)
                {
                    val += table[i][k] * mat2.table[k][j];

                }
                res.table[i][j] = val;
            }
        }
        return res;
    }
    Matrix operator+(Matrix &mat2){
        Matrix res(row , col , 0);
        for(ll i = 0 ; i < row ; i++){
            for(ll j = 0 ; j < col ; j++){
                res.table[i][j] = (table[i][j] + mat2.table[i][j]);
            }
        }
        return res;
    }
    Matrix operator^(ll n){
        Matrix res(row , col , 0);
        res = res.iden();
        Matrix dum = (*this);
        for(ll i = 0 ; i < 60 ; i++){
            if((n >> i) & 1){
                res = res * dum;
            }
            dum = dum * dum;
        }
        return res;
    }
};