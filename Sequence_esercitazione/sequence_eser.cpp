

#include "sequence_eser.h"
#include <cassert>

namespace main_savitch_3
{

	sequence::sequence()
	{
		used=0;
		current_index=CAPACITY;
	}

	void sequence::start()
	{
		if(used>0)
			current_index=0;
		else
			current_index=CAPACITY;
	}

	void sequence::advance()
	{
		assert(sequence::is_item());
			++current_index;
	}

	void sequence::insert(const value_type& entry)
	{
		assert(sequence::size()<CAPACITY);

		if(!sequence::is_item())
			sequence::start();

		for(sequence::size_type i=used; i>current_index; --i)
			data[i]=data[i-1];

		data[current_index]=entry;

		++used;
	}

	void sequence::attach(const value_type& entry)
	{
		assert(sequence::size()<CAPACITY);

		if(!sequence::is_item())
			sequence::start();

		else
			for(sequence::size_type i=used; i>current_index+1; --i)
				data[i]=data[i-1];

			data[current_index+1]=entry;

			++current_index;
			++used;
	}

	void sequence::remove_current()
	{
		if(sequence::is_item())
			for(sequence::size_type i=current_index; i<used-1; ++i)
				data[i]=data[i+1];
		--used;

		if(used==0)
			current_index=CAPACITY;
	}

	sequence::size_type sequence::size() const {return used;}

	bool sequence::is_item()const
	{
		return current_index<used;
	}

	sequence::value_type sequence::current() const
	{
		assert(sequence::is_item());

		return data[current_index];

	}



}




