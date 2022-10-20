
class droga
{
private:
	int miejscePoczatkowe;
	int miejsceKoncowe;
	bool podPrad;
public:
	droga(int _miejscePoczatkowe = 0, int _miejsceKoncowe = 0, bool _podPrad = false);
	void zmienPoczatkowe(int _poczatkowe);
	void zmienKoncowe(int _koncowe);
	void zmienpodPrad(bool _podPrad);
	int getPoczatkowe() const { return miejscePoczatkowe; }
	int getKoncowe() const { return miejsceKoncowe; }
	bool getpodPrad() const { return podPrad; }
};