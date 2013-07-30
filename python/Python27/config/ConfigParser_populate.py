#!/bin/python
from ConfigParser import SafeConfigParser

parser = SafeConfigParser()

parser.add_section('bug_tracker')
parser.set('bug_tracker', 'url', 'http://localhost:8800/bugs')
parser.set('bug_tracker', 'username', 'dhellman')
parser.set('bug_tracker', 'password', 'secret')

for section in parser.sections():
	print section
	for name, value in parser.items(section):
		print '  %s = %r' % (name, value)