
#include "atltypes.h"
class Box :
	public CRect
{
public:
	void H();
	bool m_isSelected;
	bool m_isEnd;
	CRect GetContent();
};
