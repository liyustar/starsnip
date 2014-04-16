#!/usr/bin/env python
from HTMLParser import HTMLParser
from htmlentitydefs import name2codepoint

# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser):
	not_selected = ('meta', 'link', 'input')
	def reset(self):
		HTMLParser.reset(self)
		self._level_stack = []
	def handle_starttag(self, tag, attrs):
		if not (tag in MyHTMLParser.not_selected):
			self._level_stack.append(tag)
		self._attrs = attrs
		# for attr in attrs:
	def handle_endtag(self, tag):
		if self._level_stack \
		and tag == self._level_stack[-1]:
			self._level_stack.pop()
	def handle_data(self, data):
		for (name,value) in self._attrs:
			if cmp(value, "invest-loan") == 0:
				self.do_invest_loan(data)
	def handle_comment(self, data):
		pass
	def handle_entityref(self, name):
		pass
	def handle_charref(self, name):
		pass
	def handle_decl(self, data):
		pass
	def print_stack(self):
		print "/".join(self._level_stack)

parser = MyHTMLParser();
data = open('yuexitong.html', "r")
parser.feed(data.read())
parser.print_stack()
