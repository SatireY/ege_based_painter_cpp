#include "Polygon.h"

void Polygon::Draw(bool withColor)
{
	std::vector <int> coordData;

	if (withColor)
	{
		setcolor(outlineColor->colorValue);

		if (isFill)
		{
			setfillcolor(fillColor->colorValue);
		}
		else
		{
			setfillcolor(0xFFFFFF);
		} // end of if
	}
	else
	{
		setcolor(0xCCCCCC);
		setfillcolor(0xDDDDDD);
	} // end of if

	//........... TODO .................
	/*for (int j = 0; j < *((shapeData + i)->extraData); j++)
	{
		coordData[2 * j] = ((shapeData + i)->coords + j)->x;
		coordData[2 * j + 1] = ((shapeData + i)->coords + j)->y;
	}

	*(coordData + 2 * (*((shapeData + i)->extraData))) = ((shapeData +
		i)->coords)->x;
	*(coordData + 2 * (*((shapeData + i)->extraData)) + 1) = ((
		shapeData + i)->coords)->y;

	if (shapeData[i].isFill)
	{
		fillpoly(*((shapeData + i)->extraData), coordData);
	}
	else
	{
		drawpoly(*((shapeData + i)->extraData) + 1, coordData);
	}*/
}