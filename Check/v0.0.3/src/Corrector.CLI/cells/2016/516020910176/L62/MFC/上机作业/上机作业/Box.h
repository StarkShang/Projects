
#include "atltypes.h"
class Box :
	public CRect
{
public:
	
	bool m_isSelected;
	bool m_isEnd;
	CRect GetContent();
};
