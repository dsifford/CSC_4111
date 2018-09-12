#ifndef DEREK_H
#define DEREK_H

#include <string>
#include "offense.h"

class Derek: public Offense {
	public:
		Derek();
		virtual void printStats() const;
};

#endif
