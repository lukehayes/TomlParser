# frozen_string_literal: true

def isalpha(str)
  return false if str.empty?

  !str.match(/[^A-Za-z]/)
end

def isnum(str)
  return false if str.empty?

  !str.match(/[^0-9]/)
end

lines = File.readlines('data.toml')

lines.each do |line|
  line.each_char do |c|
    if isalpha(c)
      print c

    elsif isnum(c)
      print c

    else
      case c
      when '['
        print '['
      when ']'
        print ']'
      when '='
        print '='
      when '"'
        print '"'
      when '.'
        print '.'
      when ','
        print ','
      end
    end
  end
  puts ' '
end
