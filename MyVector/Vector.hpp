#pragma once

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;
using std::cin;

namespace mine
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const 
		{
			return _start;
		}

		const_iterator end() const 
		{
			return _finish;
		}
	public:
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//复用
			//但是使用reserve必须要初始化
			this->reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}

			//原生
			/*_start = new T[v.cpacity()];
			memcpy(_start, v._start, sizeof(T) * v.size());
			_endofstorage = _start = v.capacity();
			_finish = _start + v.size();*/
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}
			_start = _finish = _endofstorage = nullptr;
		}
	public:
		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const 
		{
			return _finish - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		//传统写法
		/*vector<T>& operator= (const vector<T>& v)
		{
			if (this != &v)
			{
				delete[] this->_start;
				this->_start = new T[v.capacity()];
				//memcpy(_start, v._start, sizeof(T) * v.size());
				for (size_t i = 0; i < sz; i++)
				{
					this->_start[i] = v._start[i];
				}
				this->_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
			}
			return *this;
		}*/

		//现代写法
		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}

		T& operator[] (size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[] (size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(this->_start, v._start);
			std::swap(this->_finish, v._finish);
			std::swap(this->_endofstorage, v._endofstorage);
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start)
				{
					//std::memcpy(temp, _start, sz * sizeof(T));
					//VS中和g++不同，VS还优化了一个buf，使得短string进入buf，但是VS和g++崩溃原因是一样的，memcpy的string是浅拷贝
					//T是深拷贝的自定义类型，他们的增容或者拷贝靠系统是有问题的，所以要自己解决
					for (size_t i = 0; i < sz; i++)
					{
						temp[i] = _start[i];
						//使用string::operator= 深拷贝
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(!empty());
			_finish--;
		}

		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//更新pos，解决pos后失效
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;

			//pos = pos + 1;//传引用，解决了迭代器失效问题
			//为什么STL不解决，因为会导致一些连带错误
		}

		iterator erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}