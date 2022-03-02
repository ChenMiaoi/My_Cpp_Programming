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
			//����
			//����ʹ��reserve����Ҫ��ʼ��
			this->reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}

			//ԭ��
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

		//��ͳд��
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

		//�ִ�д��
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
					//VS�к�g++��ͬ��VS���Ż���һ��buf��ʹ�ö�string����buf������VS��g++����ԭ����һ���ģ�memcpy��string��ǳ����
					//T��������Զ������ͣ����ǵ����ݻ��߿�����ϵͳ��������ģ�����Ҫ�Լ����
					for (size_t i = 0; i < sz; i++)
					{
						temp[i] = _start[i];
						//ʹ��string::operator= ���
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
				//����pos�����pos��ʧЧ
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

			//pos = pos + 1;//�����ã�����˵�����ʧЧ����
			//ΪʲôSTL���������Ϊ�ᵼ��һЩ��������
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