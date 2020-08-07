function out=img_norm(img)

a=max(max(img));
b=min(min(img));
out=(255*(img-b))/(a-b);


end