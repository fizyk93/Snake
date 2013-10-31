#pragma once
class Object
{
public:
	Object(void);
	~Object(void);

	virtual void update() = 0;
	virtual void draw() = 0;
};

